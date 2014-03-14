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
			
			for (int letter = 0; letter < keylen; letter++)
				{
					keyvalue[letter] = (toupper(keyword[letter])) - 'A';
				}
			
			string txt = GetString();							// [0] [1] [2] [3] [4] [5] 
			int txtlen = strlen(txt);							// [b] [a] [c] [o] [n] [\0]
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
		/*		
				if (keychar < (keylen - 1))			// 1. was <= , changed to < and output was exactly the same
				{									// 2. was keylen, changed to keylen -1 and output was exactly the same
					keychar++;			// should this be int j?
				}						// no, but keychar !== int j							
				else
				{									3. I think this should be inside the if and else if above,
					keychar = 0;						not down here.
															- CORRECT!!!
															
				}									4. Problem wass with keyvalue[j]
														tried keyvalue[letter] - did not work
														decided on keyvalue[keychar] since it would be changing with each
														char typed
															****THAT FIXED IT****************
		*/	
			}
		}
		printf("\n");
		return 0;
}

