//----------------------------------------------------------------------------//
// Name: Brian Tong                                                                  //
// Student ID: 276042                                                                //
// Assignment: 2                                                               //
//----------------------------------------------------------------------------//

//generate 100 random grades, find the mean, and mode.
# include <stdio.h>
# include <stdlib.h>

//constant
# define SIZE 100

// Function prototypes.
void displayGrades(int x[], size_t size);
void loadGrades(int x[], size_t size);
void mean(int x[], size_t size);
void mode(int x[], size_t size);

//grades
int main(void)
{
	int x[100];
	loadGrades(x, SIZE);
	displayGrades(x, SIZE);
	mean(x, SIZE);
	mode(x, SIZE);
	return 0;
}

//displaying the grades in the array
void displayGrades(int x[], size_t size)
{
	size_t i;
	int count = 0;
	puts("The grades in the array are:");
	for(i = 0; i < size; i++)
	{
		printf("%d ", x[i]);
		count++; 
		if(count == 20)
		{
			puts("");
			count = 0;
		}
	}
	puts("");
	return;
}

//random grade generator 
void loadGrades(int x[], size_t size)
{
	size_t i;
	for(i = 0; i < size; i++)
	{
		x[i] = (rand()%(100 - 60)) + 60;
	}
	return;
}

//the average grade
void mean(int x[], size_t size)
{
	size_t i;
	float average;
	float total = 0;
	for(i = 0; i < size; i++)
	{
		average = x[i];
		total += average;
	}
	puts("The average grade is:");
	total = total / size;
	printf("%.2f\n\n", total); 
}

//the most common grade
void mode(int x[], size_t size)
{
	int pass, temp, prev, num;
	size_t j;
	size_t i;
	int count = 1;
	int sub = 0;
	for(pass = 1; pass < size; pass++)
	{
		for(j = 0; j < size - 1; j++)
		{
			if(x[j] > x[j + 1])
			{
				temp = x[j];
				x[j] = x[j + 1];
				x[j + 1] = temp;
			}
		}
	}
	prev = x[0];
	for (i = 0; i <= size; i++)
	{
		if(x[i] == prev)
		{
			count++;
		}
		else
		{
			prev = x[i];
			if(sub < count)
			{
				num = x[i - 1];
				sub = count;
				count = 1;
			}
			else if(sub > count)
			{
				count = 1;
			}
		}
	}
	puts("The most common grade:");
	printf("%d\n", num);
	return;
}

/*
The grades in the array are:
60 77 80 74 82 81 99 62 85 88 66 79 94 77 99 100 62 71 90 84
61 68 67 90 65 60 97 80 98 70 95 97 71 77 84 87 61 78 80 73
63 91 99 94 62 91 72 63 64 81 64 70 86 99 89 86 91 84 78 100
76 61 69 98 61 72 80 64 95 76 77 85 83 65 76 76 60 83 99 82
91 96 77 88 79 92 65 97 92 87 71 68 86 67 62 73 65 92 70 78

The average grade is:
79.30

The most common grade:
62
Press any key to continue . . .
*/

