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
			printf("You must enter a single keyword containing only letters, after the program name!\n");
			printf("ex.= jharvard $ ./caesar salad\n");
			printf("Try again, buddy.\n");
			return 1;
		}
		else 
		{
			string txt = GetString();
			int txtlen = strlen(txt);
			int keylen = strlen(argv[1]);
			
			for (int i = 0; i < txtlen; i++)
			{
				for (int j = 0; j < keylen; j++)
				{
				int keyvalue = (toupper(keyword[(j)])) - 'A';
					for (int p = 0; p < 1; p++)
					{
						if (islower(txt[i]))
						{
							char after = (((txt[i] - 'a' + keyvalue) % ALPHA) + 'a'); 
							printf("%c", after);
						}
						else if (isupper(txt[i]))
						{
							char after = (((txt[i] - 'A' + keyvalue) % ALPHA) + 'A');
							printf("%c", after);
						}
						else 
						{
							printf("%c", txt[i]);
						}
					}
				}
			}
		}
		printf("\n");
		return 0;
}

