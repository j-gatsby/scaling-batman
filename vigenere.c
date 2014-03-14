// a program that encrypts messages using Vigenere cipher
// for CS50x/2014/pset2/vigenere.c
#include <cs50.h>		// for GetString()
#include <stdio.h>		// for standard txt & output
#include <string.h>		// for strlen
#include <stdlib.h>		// for atoi
#include <ctype.h>		// for islower & isupper & isaplha

#define ALPHA 26

int main(int argc, string argv[])
{
	int a = argc;
	string keyword = argv[a - 1];
	int fail = 0;
	int pass = 0;
	for (int i = 0, n = strlen(keyword); i < n; i++)
		{
			if (!isalpha(keyword[i])) fail++;
			else pass++;
		}
		if ((a != 2) ||  (fail > 0)) 
		{
			printf("You must enter a single keyword containing only letters, output the program name!\n");
			printf("ex.= jharvard $ ./vigenere jordan\n");
			printf("Try again, buddy.\n");
			return 1;
		}
		else 
		{
			int keylen = strlen(keyword);
			int keychar = 0;			
			int keyvalue[keylen];
			
			for (int letter = 0; letter < keylen; letter++)
				{
					keyvalue[letter] = (toupper(keyword[letter])) - 'A';
				}
			
			string txt = GetString();							 
			int txtlen = strlen(txt);					
			for (int i = 0; i < txtlen; i++)
			{
				if (islower(txt[i]))
				{
					char output = ((((txt[i] - 'a') + keyvalue[keychar]) % ALPHA) + 'a'); 
					printf("%c", output);
					if (keychar < (keylen - 1))			
					{				
						keychar++;			
					}												
					else
					{
						keychar = 0;
					}
				}
				else if (isupper(txt[i]))
				{
					char output = ((((txt[i] - 'A') + keyvalue[keychar]) % ALPHA) + 'A');
					printf("%c", output);
					if (keychar < (keylen - 1))		
					{									
						keychar++;			
					}												
					else
					{
						keychar = 0;
					}
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

