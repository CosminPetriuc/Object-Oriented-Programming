#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Write a simple Hello world program that prompts the user for his / her name and birth year, and you display a greeting message as well
// as the age of the person.
// You need to check that you have exactly one command line argument and that this argument is a positive integer.


int main(int argc, char* argv[]) 
{

	char name[32];
	short year;
	
	printf("Type name: ");
    int n = scanf("%s", name);

	printf("Type birth year: ");
	int y = scanf("%hi", &year);
	if (year > 0)
		printf("Hello %s, your age is %d", name, 2023 - year);
	else
		printf("The year must be positive!");
	return 0;
}

