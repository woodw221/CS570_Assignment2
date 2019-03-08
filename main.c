/*
 * William Wood cssc1167, Nadim Tahmass cssc1158	
 * CS570, Summer 2018
 * Assignment #2, File Editor
 * main.c
 */

#include "fileEditor.h"


int main(){
	printf("\e[1;1H\e[2J");
	while(leave != 1){
		inputCheck = 0;
		//Menu Formatting and List of Commands
		
		printf("File Editor Main Menu\n");
		printf("Type 1 to create a directory\n");
		printf("Type 2 to create a file\n");
		printf("Type 3 to print a directory listing\n");
		printf("Type 4 to print a file status\n");
		printf("Type 5 to read from a file\n");
		printf("Type 6 to write to a file\n");
		printf("Type 0 to exit\n");
		
		//Checks for valid inputs and reprompts for all bad inputs
		while(inputCheck != 1){

			scanf("%s" , uInput);
			if(strlen(uInput) > 1){
			printf("Invalid Input.\n");
			memset(uInput, 0, sizeof(uInput));
			inputCheck = 0;
			}
			if(uInput[0] == '7' || uInput[0] == '8' || uInput[0] == '9'){
				printf("Invalid Input.\n");
				memset(uInput, 0, sizeof(uInput));
				inputCheck = 0;
			}
			else{
				inputCheck = 1;
			}
		}

		//Make a directory loop. Checks if 0 to return to main menu
		if(uInput[0] == '1'){
			makeDirectory();
		}
		
		//Create a regular file
		else if(uInput[0] == '2'){
			makeFile();
		}

		//Print Directory Contents
		else if(uInput[0] == '3'){
			displayDirectory();	
		}
		
		//Print File Status
		else if(uInput[0] == '4'){
			displayFileStat();
		}
		//Read a file
		else if(uInput[0] == '5'){
			readFile();
		}
		//Write to a file
		else if(uInput[0] == '6'){
			writeFiles();
		}
		
		//Closes program and Says Closing
		else if(uInput[0] == '0'){
			printf("Closing.\n");
			leave = 1;
		}
		memset(uInput, 0, sizeof(uInput));
	}
	return 0;
}
