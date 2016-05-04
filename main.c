//Preprocessor Lab
//Generates preprocessor file for string manipulation.
//Palomar ID: 008372648
//Cody Young

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


FILE *finput, *foutput;

void replaceInclude(char *p);

int main(void) {
	char *p;				//Pointer to character array - allocates memory
	char ch;				//Input variable from file
	int i = 0;				//Array looping variable
	int q = 0;				//Used to match char array and check for multiline comments
	int k = 0;				//Used in remove comment loop
	if (!(finput = fopen("test.c", "r"))) {
		printf("Error: Cannot process test file. ABORT");
		exit(1);
	}

	if (!(foutput = fopen("out.c","w"))) {
		printf("Error: Cannot open C file for output. ABORT");
		exit(1);
	}

	p = (char*)malloc(sizeof(char));										// Allocates 1 byte to char array to start

	while ((ch = fgetc(finput)) != EOF)
	{
		p[i++] = ch;														// Store first byte in char array, then increment i
		p = (char*)realloc(p, (i + 1) * sizeof(char));						// Allocate room for next byte (character) by resizing heap buffer p
		{
			if (ch == '\'')            //Check for escape comments
			{
				q = ch;
				do
				{
					putchar(ch);

				} while (ch != q);
				putchar(ch);
			}
			else if (ch == '/')					// Check for opening comment
			{
				ch = fgetc(finput);
				if (ch != '*')                  // If not multiline, move file pointer back
				{
					putchar(' ');
					fseek(finput, -1, SEEK_CUR);
				}
				else
				{
					if (ch != '/') {				//Read until end of line - replace comment with whitespace(need to fix)
						fgetc(finput);
						putchar(' ');               //Replace comment with whitespace
						do
						{
							k = ch;
							ch = fgetc(finput);
						} while (ch != '/' || k != '*');
					}
				}
			}
			else
			{
				putchar(ch);
				fputc(ch, foutput);
			}
		}
	}
		
	p[i] = '\0';

	free(p);

	fclose(finput);
	fclose(foutput);

	return 0;
}

void replaceInclude(char *p) {

}

