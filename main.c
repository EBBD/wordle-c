#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "color.h"
#include "dictionary.h"

int main(int argc, char** argv){
	int words = numberOfWords();
	char* secret = pickWord();
	int guessCount = 0;

	while(guessCount < 6){
		char guess[9];
		printf("Enter Guess #%d: ", guessCount);
		scanf("%s", guess);

		if(strlen(guess) != 5 || isWordValid(guess) == 0){
			printf("Invalid guess, try again");
			continue;
		}
		if(strcmp(secret, guess) == 0){
			printGreen('Y');
			printf("ou Win!!!");
			return 0;
		}
		printGuess(secret, guess);
		guessCount++;
	}
	printRed('Y');
	printf("ou Lose!!!");
	free(secret);
	return 0;
}
