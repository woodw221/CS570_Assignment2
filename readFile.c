/*
 * William Wood cssc1167, Nadim Tahmass cssc1158	
 * CS570, Summer 2018
 * Assignment #2, File Editor
 * readFile.c
 */

//Reads a file and prints to stdout

#include "fileEditor.h"

int status = 0;

void readFile(){
		
	memset(uInput, 0, sizeof(uInput));

	printf("\e[1;1H\e[2J");
	printf("Input a file name to read or 0 to return to main menu\n");

	scanf("%s", uInput);
	if(strlen(uInput) == 1 && uInput[0] == '0'){
		printf("Returning to main menu\n");
		sleep(1);
	}
	else{
		//Create child to create shadow file
		for(int id=0; id<1; id++){
			if((child_pid = fork()) == 0){
				copyFile(uInput);
				exit(0);
			}
		}
		//Wait for child to finish before continuing
		while ((wpid = wait(&status)) > 0);
	
		//Read to stdout
		uInput[strlen(uInput)] = '.';
		uInput[strlen(uInput)] = 'b';
		uInput[strlen(uInput)] = 'a';
		uInput[strlen(uInput)] = 'k';

		file1 = open(uInput, O_RDONLY);
		if(file1 < 0){
			printf("File failed to open returning to main menu.\n");
		}
		while(1){
			in = read(file1, buffer, bufferSize);
			if (in <= 0){
				break;
			}
			printf("%s", buffer);
		}
		printf("\n");
	}
}
