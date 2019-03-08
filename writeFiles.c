/*
 * William Wood cssc1167, Nadim Tahmass cssc1158	
 * CS570, Summer 2018
 * Assignment #2, File Editor
 * writeFiles.c
 */

//Writes files then organizes them

#include "fileEditor.h"

void writeFiles(){
	memset(uInput, 0, sizeof(uInput));

	printf("\e[1;1H\e[2J");
	printf("Input a file name to write to or 0 to return to main menu\n");

	scanf("%s", uInput);
			
	if(strlen(uInput) == 2 && uInput[0] == '0'){
		printf("Returning to main menu\n");
		sleep(1);
	}
	else{
		for(int id=0; id<1; id++){
			if((child_pid = fork()) == 0){
				copyFile(uInput);
				exit(0);
			}
		}
		while ((wpid = wait(&status)) > 0);

		uInput[strlen(uInput)] = '.';
		uInput[strlen(uInput)] = 'b';
		uInput[strlen(uInput)] = 'a';
		uInput[strlen(uInput)] = 'k';

		printf("\e[1;1H\e[2J");
		printf("Type 1 to write to the file\n");
		printf("Type 2 to append to the file\n");
		printf("Type 3 to insert at a specific byte to the file\n");

		//Needed for formatting for some reason
		fgets(buffer, 1024, stdin);

		memset(buffer, 0, sizeof(buffer));
		inputCheck = 0;
		while(inputCheck != 1){

			fgets(buffer, 1024, stdin);
			if(strlen(buffer) > 2){
				printf("Invalid Input.\n");
				memset(buffer, 0, sizeof(buffer));
				inputCheck = 0;
			}
			else if(buffer[0] == '1' || buffer[0] == '2' || buffer[0] == '3'){
					inputCheck = 1;
			}

			else{
				printf("Invalid Input.\n");
				memset(buffer, 0, sizeof(buffer));
				inputCheck = 0;
			}
		}
			
		if(buffer[0] == '1'){
			file1 = open(uInput, O_RDONLY | O_WRONLY | O_TRUNC);
			memset(buffer, 0, sizeof(buffer));
					
			printf("Write to the file up to 1024 bytes.\n");
			printf("Type 0 to return to the main menu.\n");
			
			while(1){
				fgets(buffer, 1024, stdin);

				if(buffer[0] == '0' && strlen(buffer) == 2){
					break;
				}

				out = write(file1, buffer, strlen(buffer));
						
			}

			close(file1);
			//Child processes to sort and update
			for(int id=0; id<3; id++){
				if((child_pid = fork()) == 0){
							
					if(id == 0){
						fileBak(uInput);
						exit(0);
						}
					else if(id == 1){
						alphWords();
						createAlph();
						exit(0);
					}
					else if(id == 2){
						alphWords();
						createBack();
								exit(0);
					}
					exit(1);
			}
						
						
		}//Wait for children
		while ((wpid = wait(&status)) > 0);
					
										

					

		}
				
		if(buffer[0] == '2'){
			file1 = open(uInput, O_RDONLY | O_WRONLY | O_APPEND);
			memset(buffer, 0, sizeof(buffer));
					
			printf("Write to the file up to 1024 bytes.\n");
			printf("Type 0 to return to the main menu.\n");
			
			while(1){
				fgets(buffer, 1024, stdin);

				if(buffer[0] == '0' && strlen(buffer) == 2){
					break;
				}

				out = write(file1, buffer, strlen(buffer));
						
			}

			close(file1);
			//Child Processes to sort and update
			for(int id=0; id<3; id++){
				if((child_pid = fork()) == 0){
							
					if(id == 0){
						fileBak(uInput);
						exit(0);
					}
					else if(id == 1){
						alphWords();
						createAlph();
						exit(0);
					}
					else if(id == 2){
						alphWords();
						createBack();
						exit(0);
					}
					exit(1);
				}
						
						
			}//Waiting for children to finish
			while ((wpid = wait(&status)) > 0);

		}

		if(buffer[0] == '3'){
			printf("How many bytes deep do you want to start writing.\n");
			memset(buffer, 0, sizeof(buffer));

			fgets(buffer, 1024, stdin);

			fr = fopen(uInput, "r+");

			int pos = atoi(buffer);					
			fseek(fr, pos, SEEK_CUR);

			memset(buffer, 0, sizeof(buffer));
					
			printf("Write to the file up to 1024 bytes.\n");
			printf("Type 0 to return to the main menu.\n");
			
			while(1){
				fgets(buffer, 1024, stdin);

				if(buffer[0] == '0' && strlen(buffer) == 2){
					break;
				}

				fputs(buffer, fr);
						
			}
			fclose(fr);
			//Child Processes to sort and update
			for(int id=0; id<3; id++){
				if((child_pid = fork()) == 0){
						
					if(id == 0){
						fileBak(uInput);
						exit(0);
							}
					else if(id == 1){
						alphWords();
						createAlph();
						exit(0);
					}
					else if(id == 2){
						alphWords();
						createBack();
						exit(0);
					}
					exit(1);
				}
						
						
			} //Wait for children
			while ((wpid = wait(&status)) > 0);

		}

	}
}
