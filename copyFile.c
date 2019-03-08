/*
 * William Wood cssc1167, Nadim Tahmass cssc1158	
 * CS570, Summer 2018
 * Assignment #2, File Editor
 * copyFile.c
 */

//Holds all of our big file copying functions

#include "fileEditor.h"

//Copy a file into .bak
void copyFile(char *nameCpy){
			

		file1 = open(nameCpy, O_RDONLY);
		if(file1 < 0){
			printf("File does not exist returning to main menu.\n");
			exit(1);
		}
		//Adds .bak extension to the end of file name
		nameCpy[strlen(nameCpy)] = '.';
		nameCpy[strlen(nameCpy)] = 'b';
		nameCpy[strlen(nameCpy)] = 'a';
		nameCpy[strlen(nameCpy)] = 'k';

		remove(nameCpy);

		file2 = creat(nameCpy, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
		if(file2 <0){
			printf("Shadow file failed to create returning to main menu.\n");
			exit(1);
		}

		while(1){
			in = read(file1, buffer, bufferSize);
			if (in <= 0){
				break;
			}	
			
			out = write(file2, buffer, in);
			if(out <= 0){
				break;
			}
		}
		close(file1);
		close(file2);

}

//Copy a file into .bak
void fileBak(char *nameCpy){
			

		file1 = open(nameCpy, O_RDONLY);
		if(file1 < 0){
			printf("File does not exist returning to main menu.\n");
			exit(1);
		}
		//Adds .bak extension to the end of file name
		nameCpy[strlen(nameCpy)-1] = 0;
		nameCpy[strlen(nameCpy)-1] = 0;
		nameCpy[strlen(nameCpy)-1] = 0;
		nameCpy[strlen(nameCpy)-1] = 0;

		remove(nameCpy);

		file2 = creat(nameCpy, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
		if(file2 <0){
			printf("Shadow file failed to create returning to main menu.\n");
			exit(1);
		}

		while(1){
			in = read(file1, buffer, bufferSize);
			if (in <= 0){
				break;
			}	
			
			out = write(file2, buffer, in);
			if(out <= 0){
				break;
			}
		}
		close(file1);
		close(file2);

}

