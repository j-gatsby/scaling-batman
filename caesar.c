// a program that encrypts messages using Caesar’s cipher
// for CS50x/2014/pset2/caesar.c
#include <cs50.h>		// for GetString()
#include <stdio.h>		// for standard input & output
#include <string.h>		// for strlen
#include <stdlib.h>		// for atoi

#define ALPHA 26

int main(int argc, string argv[])
{
	int n = argc;
	int key = (int)atoi(argv[n - 1]);
	if ((argc != 2) || (key < 0)) 
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
			if (input[i] >= 'a' && input[i] <= 'z') 
			{
				char after = (((input[i] - 'a' + key) % ALPHA) + 'a'); 
				printf("%c", after);
			}
			else if (input[i] >= 'A'&& input[i] <= 'Z')
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

