/*
 * William Wood cssc1167, Nadim Tahmass cssc1158	
 * CS570, Summer 2018
 * Assignment #2, File Editor
 * alphWords.c
 */

//Organizes words alphabetically

#include "fileEditor.h"

int myCompare(const void *a, const void *b){
	return strcasecmp(a, b);
}

void alphWords(){
	memset(buffer, 0, sizeof(buffer));
	
	fr = fopen(uInput, "r");
	if (fr != NULL){
	
		while(wordCount < bufferSize && fscanf(fr, "%s", orderedWords[wordCount]) != -1){
			++wordCount;
		}
		
		qsort(orderedWords[0], wordCount, bufferSize, myCompare);
	
	}
	fclose(fr);
	
}
