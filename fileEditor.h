/*
 * William Wood cssc1167, Nadim Tahmass cssc1158	
 * CS570, Summer 2018
 * Assignment #2, File Editor
 * fileEditor.h
 */

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<strings.h>
#include<dirent.h>

char uInput[100];
int file1, file2, in, out, inputCheck, leave;
#define bufferSize 1024
char buffer[bufferSize];
#define projectWordCount 2000
char orderedWords[projectWordCount][100];
char *found;
char *alph, *back, newName[100];


struct dirent *de;
DIR *dr;

FILE *fr;

pid_t child_pid, wpid;
int status;

int wordCount;

//Creates the alphabitized file and fills it accordingly
int createAlph();

//Creates the alphabitized backwards file and fills it accordingly
int createBack();

//Quick way to compare strings to alphabitize
int myCompare(const void *a, const void *b);

//Copies a file into a .bak version
void copyFile(char *nameCpy);

//Copies the .bak version to the regular after a safe edit
void fileBak(char *nameCpy);

//Alphabitizes words in conjunction with myCompare
void alphWords();

//Makes a directory
void makeDirectory();

//Makes a regular file
void makeFile();

//Displays Directory Contents
void displayDirectory();

//Displays File Status
void displayFileStat();

//Reads a file and puts it into stdout
void readFile();

//Writes files and organizes them accordingly
void writeFiles();

