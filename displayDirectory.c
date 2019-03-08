/*
 * William Wood cssc1167, Nadim Tahmass cssc1158	
 * CS570, Summer 2018
 * Assignment #2, File Editor
 * displayDirectory.c
 */

//Displays Directories and File Status

#include "fileEditor.h"

void displayDirectory(){
	memset(uInput, 0, sizeof(uInput));
			
	printf("\e[1;1H\e[2J");
	printf("Enter . to print the current directory.\n");
	printf("Or enter a directory name in the working directory to print.\n");
	printf("Or enter 0 to return to main menu.\n");

	scanf("%s", uInput);
	if(strlen(uInput) == 1 && uInput[0] == '0'){
		printf("Returning to main menu\n");
		sleep(1);
	}

	else if(strlen(uInput) == 1 && uInput[0] == '.'){
		dr = opendir(".");
		while((de = readdir(dr)) != NULL){
			printf("%s\n", de->d_name);
		}
	}

	else{
		if((dr = opendir(uInput)) == NULL){
			printf("Directory can not be opened or does not exist");
		}
		else{
			dr = opendir(uInput);
			while((de = readdir(dr)) != NULL){
				printf("%s\n", de->d_name);
			}	
		}
	}		
}

void displayFileStat(){
	printf("\e[1;1H\e[2J");
	printf("Enter the name of the file you wish to see the status of.\n");
	printf("Or print the path to a file in a child directory of the working directory.\n");
	printf("Or print 0 to return to the main menu.\n");

	struct stat *fileStat;
	fileStat = malloc(sizeof(struct stat));
			

	scanf("%s", uInput);
	if(strlen(uInput) == 1 && uInput[0] == '0'){
		printf("Returning to main menu\n");
		sleep(1);
	}
	else{
		//if given an invalid file name or location
		if(stat(uInput, fileStat) < 0){
			printf("Invalid file returning to main menu.\n");
		}

		else{
			printf("File Status for %s\n", uInput);
			printf("File Size: \t\t%ld bytes\n", fileStat->st_size);
			printf("Number of Links: \t%lu\n", fileStat->st_nlink);
			printf("File inode: \t\t%lu\n", fileStat->st_ino);
					
			printf("File Permissions: \t");
			printf( (S_ISDIR(fileStat->st_mode)) ? "d" : "-");
			printf( (fileStat->st_mode & S_IRUSR) ? "r" : "-");
			printf( (fileStat->st_mode & S_IWUSR) ? "w" : "-");
			printf( (fileStat->st_mode & S_IXUSR) ? "x" : "-");
			printf( (fileStat->st_mode & S_IRGRP) ? "r" : "-");
			printf( (fileStat->st_mode & S_IWGRP) ? "w" : "-");
			printf( (fileStat->st_mode & S_IXGRP) ? "x" : "-");
			printf( (fileStat->st_mode & S_IROTH) ? "r" : "-");
			printf( (fileStat->st_mode & S_IWOTH) ? "w" : "-");
			printf( (fileStat->st_mode & S_IXOTH) ? "x" : "-");
			printf("\n\n");

			printf("This file %s a symbolic link\n\n", (S_ISLNK(fileStat->st_mode)) ? "is" : "is not");
		}
			
				
	}
			
	free(fileStat);
			
}
