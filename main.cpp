#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int searchForString(char *fileName, char *string){
	FILE *file;
	char buffer[1024];
	
	file = fopen(fileName, "r");
	fgets(buffer, 1024, file);
	if(strstr(buffer, string)!=NULL){
		return 1;
	}
	return 0;
}

int main(){
	char *checkString;
	checkString = "I want to learn PE file format!";
	char *fileName;
	FILE *file;
	fileName = "PE-1.txt";
	char data[1024] = {73, 32, 119, 97, 110, 116, 32, 108, 101, 97, 114, 110, 32, 80, 69, 32, 102, 105, 108, 101, 32, 102, 111, 114, 109, 97, 116, 33};
	
	if(access(fileName, F_OK) != -1){
		if(searchForString(fileName, checkString) == 1){
		    printf("File and Line found");
			return 0;
		} 
		else{
			file = fopen(fileName, "a");
			fprintf(file, " %s", checkString);
			fclose(file);
			printf("File found but line not found");
			return 0; 
		}
	}
	else{
		file = fopen(fileName, "w");
		if(file == NULL){
			exit(EXIT_FAILURE);
		}
		fputs(data, file);
		fclose(file);
		printf("No file found");
		return 0;
	}
}
	
