/*
 ============================================================================
 Name        : Prompt.c
 Author      : 
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked.h"


linked* listLinked;

void print_entry(char *entry) {
	printf("You entered: %s\n", entry);
}


int main(int argc, char *argv[]) {
	char input[201];
	listLinked = (linked*) calloc(1,sizeof(linked));
	while(1) {
		printf("prompt> ");
		if (fgets(input, 200, stdin) == NULL) {
			printf("An error ocurred.\n");
			break;
		}

		if (strncmp(input, "put", 3) == 0) {
			put(listLinked,atoi(input+4));
		}
		
		if (strncmp(input, "get", 3) == 0) {
			get(listLinked,atoi(input+4));
		
		}
		if (strncmp(input, "first\n", 6) == 0) {
			first(listLinked);
	
		}
		if (strncmp(input, "last\n", 5) == 0) {
			last(listLinked);

		}
		if (strncmp(input, "remove", 6) == 0) {
			remo(listLinked,atoi(input+7));
		}
		if (strncmp(input, "list\n", 5) == 0) {
			list(listLinked);
		}
		if (strncmp(input, "clear\n", 6) == 0) {
			clear(listLinked);
		}

		if (strncmp(input, "exit\n", 5) == 0) {
			break;
		}
		//print_entry(input);
	}

	return EXIT_SUCCESS;
}
