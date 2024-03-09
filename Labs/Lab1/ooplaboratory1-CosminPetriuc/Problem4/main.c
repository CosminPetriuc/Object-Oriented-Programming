#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "tests.h"

// Substitution cipher or Caesar’s cipher.

// This program which reads a natural number n and a string s. The string s is encoded using Caesar’s cipher with a displacement of n (either positive or negative).
// The program decodes the message and display it on the screen. Punctuation marks and numbers are left as they are.


// DO NOT CHANGE THE SIGNATURE OF THIS METHOD
void encrypt(char s[], int n) {
	int a;

	for (int i = 0; i < strlen(s); i++)
		if (isalpha(s[i]))
		{
			a = s[i] + n;

			if (isupper(s[i]))
			{
				while (a < 65)
					a += 26;
				while (a > 90)
					a -= 26;
			}
			else
			{
				while (a < 97)
					a += 26;
				while (a > 122)
					a -= 26;
			}

			s[i] = (char)a;

		}
	printf("%s", s);

}

int main()
{

	// To enable the tests, ctrl+click on ENABLE_TESTS (or go to the file "tests.h") and change the line
	// #define ENABLE_TESTS 0
	// to:
	// #define ENABLE_TESTS 1
#if ENABLE_TESTS > 0
	run_tests(true);
#endif
	int n;
	char s[1000];
	printf("Give a number: ");
	int r = scanf("%d\n", &n);
	if (r != 1)
		printf("Error!");
	fgets(s, 1000, stdin);

	int a;
	char msg[1000];
	int key = 0;
	encrypt(msg, &key);

	return 0;
}