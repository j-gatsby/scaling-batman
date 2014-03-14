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
	string keyword = argv[a - 1];
	for (int i = 0, n = strlen(keyword); i < n; i++)
		{
			if (!isalpha(keyword[i])) fail++;
			else pass++;
		}
		if ((a != 2) ||  (fail > 0)) 
		{
			printf("You must enter a single keyword containing only letters, after the program name!\n");
			printf("ex.= jharvard $ ./caesar salad\n");
			printf("Try again, buddy.\n");
			return 1;
		}
		else 
		{
			string input = GetString();
			
			for (int i = 0, n = strlen(input); i < n; i++)
			{
				for (int j =0; argv[1][j] != '\0'; j++)
				{
				char keyletter = (toupper(keyword[j])) - 'A';
					
					if (islower(input[i]))
					{
						char after = (((input[i] - 'a' + keyletter) % ALPHA) + 'a'); 
						printf("%c", after);
					}
					else if (isupper(input[i]))
					{
						char after = (((input[i] - 'A' + keyword[j]) % ALPHA) + 'A');
						printf("%c", after);
					}
					else 
					{
						printf("%c", input[i]);
					}
				}
			}
		}
		printf("\n");
		return 0;
}

