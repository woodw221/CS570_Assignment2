/*
 * William Wood cssc1167, Nadim Tahmass cssc1158	
 * CS570, Summer 2018
 * Assignment #2, File Editor
 * organizedFiles.c
 */

//Creates the alphabetical file and the backwards alphabetical

#include "fileEditor.h"

int wordCount = 0;

char *alph = "alph", *back = "back", newName[100];

int createAlph(){
	//Create alphabitized file
	found = strchr(uInput, '.');
	
	strncpy(newName, uInput, strlen(uInput)-strlen(found));
	newName[strlen(found)];
	strcat(newName, alph);
	strcat(newName, found);
	
	remove(newName);			
	fr = fopen(newName, "w+");
										
	for(int k=0; k<wordCount;k++){	
		fprintf(fr, "%s", orderedWords[k]);
		fprintf(fr, "\n");
	}
	fclose(fr);
	return 0;
}


int createBack(){
	//Create alphabitized backwards
	found = strchr(uInput, '.');
					
	strncpy(newName, uInput, strlen(uInput)-strlen(found));
	newName[strlen(found)];
	strcat(newName, back);
	strcat(newName, found);

	remove(newName);
	fr= fopen(newName, "w+");

	for(int k=wordCount-1; 0<=k;k--){	
		fprintf(fr, "%s", orderedWords[k]);
		fprintf(fr, "\n");
		}
	fclose(fr);
	return 0;
}
