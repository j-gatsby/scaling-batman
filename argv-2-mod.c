// modified version of argv-2 from CS50x/2014/Walkthroughs/Week 02
// Program prints out the command-line arguments, originally with each
//	char on it's own line
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
	// print arguments
	for (int i = 0; i < argc; i++)
	{
		for (int j =0, n = strlen(argv[i]); j < n; j++)
		{
			printf("%c", argv[i][j]);						// \n was after %c originally
		}
	}
	printf("\n");											// moved to print on a single line
}
