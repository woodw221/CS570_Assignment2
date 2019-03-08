/*
 * William Wood cssc1167, Nadim Tahmass cssc1158	
 * CS570, Summer 2018
 * Assignment #2, File Editor
 * makeDirectory.c
 */

//Creates directories and regular files

#include "fileEditor.h"

void makeDirectory(){
	memset(uInput, 0, sizeof(uInput));

	printf("\e[1;1H\e[2J");
	printf("Input a directory name or 0 to return\n");
			
	scanf("%s", uInput);
	if(strlen(uInput) == 1 && uInput[0] == '0'){
		printf("Returning to main menu\n");
		sleep(1);
	}
	else{
		mkdir(uInput, 0700);
	}
}


void makeFile(){
	memset(uInput, 0, sizeof(uInput));
	
	printf("\e[1;1H\e[2J");
	printf("Enter the name of the file you wish to create.\n");
	printf("Or enter 0 to return to main menu.\n");
			
	scanf("%s", uInput);
	if(strlen(uInput) == 1 && uInput[0] == '0'){
		printf("Returning to main menu\n");
		sleep(1);
		}
	else{
		creat(uInput, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
		}
}
