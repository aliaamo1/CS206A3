#include "list.h"
#include<string.h>

int main() {
	char name[100];
	printf("Enter name of text file.");
	scanf("%s", name);
	
	FILE* fp = fopen(name, "r");
	while(fp == 0) {
		printf("Enter name of text file.");
  	        scanf("%s", name);
	        fp = fopen(name, "r");

	}

	while(feof(fp) == 0) {
		int numberRead;
		fscanf(fp, "%d\n", &numberRead);
		add(numberRead);
	}
	prettyPrint();
	int numberEntered;
	BOOLEAN numberFound;
	BOOLEAN keepGoing = TRUE;

	while( keepGoing){
		printf("Enter int number");
		scanf("%d", &numberEntered);
	
		numberFound = delete(numberEntered);
		if(numberFound == TRUE) {
			printf("NUMBER WAS DELETED\n");
		}
		else{
			printf("NUMBER WAS NOT FOUND\n");
		}

		prettyPrint();
		char usrAnswer [4];
		printf("Do you want to delete another number?");
		scanf("%s", usrAnswer);
	
		if(strcmp(usrAnswer,"Y") != 0 && strcmp(usrAnswer,"y") != 0 &&
			strcmp(usrAnswer,"YES") != 0 && strcmp(usrAnswer,"yes")!=0
 			&& strcmp(usrAnswer,"Yes") != 0) {
				keepGoing = FALSE;		
		}	

	}
	return 0;
}
