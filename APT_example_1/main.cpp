// A test program that sums up two numbers
// Guntis Arnicans

#include "stdio.h"
#include "stdlib.h"

int main(void)
{
	FILE* inFile;
	FILE* outFile;
	int aFirst;  // thefirst number
	int aSecond; // the second number
	int aResult; // the result
	char aString[101]; // place to read a string of symbols

// Opening of files
	inFile = fopen("addition.in", "r");  // open the file in read-only mode, otherwise APTS will not allow the file to be opened
	outFile = fopen("addition.out", "w+");

	fscanf(inFile, "%s", aString);  // we read a series of symbols to the first space or 'white symbol'
	fscanf(inFile, "%d %d", &aFirst, &aSecond); // we read two numbers with one or more spaces between them

	aResult = aFirst + aSecond;

// --- example for screen printing, these results can be seen on the APTS response page
// --- in the final version such prints must not be left !!!
	fprintf(stdout, "%s\n", aString);
	fprintf(stdout, "Number1: %d\n", aFirst);
	fprintf(stdout, "Number2: %d\n", aSecond);
	fprintf(stdout, "Result: %d\n", aResult);
// --- end of the example to print on the screen

// real printing to a file
	fprintf(outFile, "%s%s", aString, ": ");
	fprintf(outFile, "%d\n", aResult);


// we close the files
	fclose(inFile);
	fclose(outFile);

	return 0;
}
