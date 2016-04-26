//Preprocessor Lab
//Generates preprocessor file for string manipulation.
//Palomar ID: 008372648
//Cody Young

#include <stdio.h>
#include <stdlib.h.>

FILE *finput, *foutput;

int main(void) {
	char *p;
	int i = 0;
	char ch;

	if (!(finput = fopen("test.c", "r"))) {
		printf("Error: Cannot process test file. ABORT");
		exit(1);
	}

	if (!(foutput = fopen("out.c","w"))) {
		printf("Error: Cannot open C file for output. ABORT");
		exit(1);
	}

	p = (char*)malloc(sizeof(char));					// Allocates 1 byte to char array to start

	while ((ch = fgetc(finput)) != EOF)
	{
		p[i++] = ch;									// Store first byte
		p = (char*)realloc(p, (i + 1)*sizeof(char));	// Allocate room for next byte (character) by resizing heap buffer p
	} 

	p[i] = '\0';
	printf("%s\n", p);
	free(p);
	fclose(finput);

	return 0;
}