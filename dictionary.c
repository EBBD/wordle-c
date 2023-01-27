#include <stdio.h>
#include <string.h>
#include "color.h"
#include "dictionary.h"

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

char* pickWord(){
	//open the file and count the number of words
	//pick a random number
	//get that word from the dictionary
	//return the word
	
}
