#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Alice forgot her card’s PIN code.She remembers that her PIN code had 4 digits, all the digits were distinctand in decreasing order, 
// and that the sum of these digits was 24. 
// This C program that prints, on different lines, all the PIN codes which fulfill these constraints. 

int main(int argc, char* argv[]) 
{

	for (int a = 9; a >= 3; a--)
		for (int b = a - 1; b >= 2; b--)
			for (int c = b - 1; c >= 1; c--)
			{
				int d = 24 - (a + b + c);
				if (d < c && d >= 0)
					printf("%d%d%d%d\n", a, b, c, d);
			}

	return 0;
}

