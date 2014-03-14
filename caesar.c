// a program that encrypts messages using Caesar’s cipher
// for CS50x/2014/pset2/caesar.c
#include <cs50.h>		// for GetString()
#include <stdio.h>		// for standard input & output
#include <string.h>		// for strlen
#include <stdlib.h>		// for atoi
#include <ctype.h>		// for islower & isupper

#define ALPHA 26

int fail;
int pass;

int main(int argc, string argv[])
{
	int a = argc;
	string k = argv[a - 1];
	int key = (int)atoi(k);
	for (int i = 0, n = strlen(k); i < n; i++)
		{
			if (!isdigit(k[i])) fail++;
			else pass++;
		}
		if ((a != 2) || (key < 0) || fail > 0) 
		{
			printf("You must enter a single, non-negative int to use as the key, after the program name!\n");
			printf("ex.= jharvard $ ./caesar 13\n");
			printf("Try again, buddy.\n");
			return 1;
		}
		else 
		{
			string input = GetString();

			for (int i = 0, n = strlen(input); i < n; i++)
			{
				if (islower(input[i]))
				{
					char after = (((input[i] - 'a' + key) % ALPHA) + 'a'); 
					printf("%c", after);
				}
				else if (isupper(input[i]))
				{
					char after = (((input[i] - 'A' + key) % ALPHA) + 'A');
					printf("%c", after);
				}
				else 
				{
					printf("%c", input[i]);
				}
			}
		}	
		printf("\n");
		return 0;
}

