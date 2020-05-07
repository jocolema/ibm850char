#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Globals for matrix calculations

int i = 1;
int j = 1;
int matrix[14][16];
int character = 32;

void chart();
int returnASCII(int row, int column);
void charLookUp();
void quitApplication();

int main(int argc, char **argv)
{
	system("clear");
	
	printf("\033[0;35m");
	fprintf(stdout, "		###################################\n		#				  #\n		#  Created by John J. Coleman as  #\n		#    a tool to be used for low    #\n		#      level console coding.      #\n		#  Western-IBM850 Char Encoding   #\n		#				  #\n		###################################\n\n");

	chart();
	charLookUp();

	return 0;
}

// Format of the chart with ASCII characters

void chart()
{
	printf("    ");

	while(j < 17)
	{
		printf("\033[1;31m");
		if(j < 9)
			fprintf(stdout, "%i   ", j);
		else
			fprintf(stdout, "%i  ", j);
		j++;
	}
	
	j = 0;
	fprintf(stdout, "\n\n");

	while(i < 15)
	{
		printf("\033[1;32m");
		if(i < 10)
			fprintf(stdout, "%i   ", i);
		else
			fprintf(stdout, "%i  ", i);
		while(j < 16)
		{
			printf("\033[0;36m");
			j++;
			matrix[i][j] = character;
			fprintf(stdout, "%c   ", matrix[i][j]);
			character++;
		}
		printf("\n\n");
		j = 0;
		i++;
	}
}

// returns the value of the ASCII value on the chart

int returnASCII(int row, int column)
{
	return matrix[row][column];
}

// Script to allow user to enter a row and column value of the character they want to use - this returns the correct ASCII value.

void charLookUp()
{
	int row;
	int column;
	int total;
	bool running = true;

	while(running)
	{
		fprintf(stdout, "\nWhich row? ");
		fscanf(stdin, "%i", &row);
		fprintf(stdout, "Which column? ");
		fscanf(stdin, "%i", &column);
	
		total = returnASCII(row, column);

		if(row > 14 || column > 16)
			fprintf(stdout, "\nRow or Column value exceeds range... Try again.\n");
		else
			fprintf(stdout, "\n%c : %i\n", total, total);
	}
}
