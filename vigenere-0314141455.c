// a program that encrypts messages using Caesar’s cipher
// for CS50x/2014/pset2/caesar.c
#include <cs50.h>		// for GetString()
#include <stdio.h>		// for standard txt & output
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
			printf("You must enter a single keyword containing only letters, output the program name!\n");
			printf("ex.= jharvard $ ./caesar salad\n");
			printf("Try again, buddy.\n");
			return 1;
		}
		else 
		{
			int keylen = strlen(keyword);
			int keychar = 0;
			int keyvalue[keylen];
			for (int j = 0; j < keylen; j++)
				{
				keyvalue[j] = ((toupper(keyword[(j)])) - 'A');
				}
			
			string txt = GetString();
			int txtlen = strlen(txt);
			for (int i = 0; i < txtlen; i++)
			{
				if (islower(txt[i]))
				{
					char output = ((((txt[i] - 'a') + keyvalue[j]) % ALPHA) + 'a'); 
					printf("%c", output);
				}
				else if (isupper(txt[i]))
				{
					char output = ((((txt[i] - 'A') + keyvalue[j]) % ALPHA) + 'A');
					printf("%c", output);
				}
				else 
				{
					printf("%c", txt[i]);
				}
			}
		}
		printf("\n");
		return 0;
}

