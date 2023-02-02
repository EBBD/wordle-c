#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "color.h"
#include "dictionary.h"
int isWordValid(char* str){
	//look at every word in dict, present words are valid, otherwise invalid	
	FILE* fp = fopen("dictionary.txt", "r");
	if (fp == NULL){
		printf("Failed to open dictionary \n");
		return 0;
	}

	char buffer[6];
	while(fscanf(fp, "%s", buffer) == 1){
		if (strcmp(str, buffer) == 0){
			return 1;
		}
	}

	//word not found, return false
	return 0;
}
int numberOfWords(){
	FILE* fp = fopen("dictionary.txt", "r");
	if(fp == NULL){
		printf("Failed to open dictionary");
		return -1;
	}

	char buffer[6];
	int count = 0;
	while(fscanf(fp, "%s", buffer) == 1){
		count++;
	}
	fclose(fp);
	return count;
}

void printGuess(char* word, char* guess){
	if(strlen(word) != 5){
		printRed('E');
		printf("rror: invalid secret word!\n");
		return;
	}
	if(strlen(guess) != 5){
		printRed('E');
		printf("rror: invalid guess!\n");
		return;
	}
	for(int i = 0; i < 5; i++){
		if (word[i] ==  guess[i]){
			printGreen(word[i]);
		}
		else if(strcontains(guess[i], word) == 1){
			printYellow(guess[i]);
		}
		else{
			printRed(guess[i]);
		}
	}
	printf("\n");
}
int strcontains(char c, char* str){
	for(int i = 0; i < 5; i++){
		if(str[i] == c){
			return 1;
		}
	}	
	return 0;
}
char* pickWord(){
	//open the file and count the number of words
	int wordCount = numberOfWords();
	//pick a random number
	srand(time(NULL));
	int index = rand() % wordCount;

	//get that word from the dictionary
	FILE* fp = fopen("dictionary.txt", "r");
	char* word = (char*)malloc(sizeof(char)*6);
	for(int i = 0; i < index; i++){
		fscanf(fp, "%s", word);
	}
	fclose(fp);
	//return the word
	return word;
}
