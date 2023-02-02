#include <stdio.h>
#include "color.h"

void printWhite(char str){
	printf("\e[1;37m%c\e[1;0m", str);
}

void printGreen(char str){
	printf("\e[1;32m%c\e[1;0m", str);
}

void printYellow(char str){
	printf("\e[1;33m%c\e[1;0m", str);
}

void printRed(char str){
	printf("\e[1;31m%c\e[1;0m", str);
}

