//
// Name: Brian Tong                                                                    //
// Student ID: 276042                                                                //
// Assignment: 3                                                               //
//----------------------------------------------------------------------------//

//encrypting and decrypting a user's input 
#include <stdio.h>

//prototype
void decryptString(char main[], char code[], int *tFactor, int *sFactor, int *amount);
void encryptString(char main[], char code[], int *tFactor, int *sFactor, int *amount);
void getData(char code[], int *tFactor, int *sFactor);

//constant
# define CODE 38
# define SIZE 100

//declare variables
int main(void)
{
	char main[CODE] = "abcdefghijklmnopqrstuvwxyz0123456789 ";
	char code[SIZE]; 
	int tFactor = 0, sFactor = 0, amount = 0;
	getData(code, &tFactor, &sFactor);
	encryptString(main, code, &tFactor, &sFactor, &amount);
	printf("\nThe encrypted string is: %s\n", code);
	decryptString(main, code, &tFactor, &sFactor, &amount);
	printf("The decrypted string is: %s\n", code);
	return 0;
}

//decrypting the encryption
void decryptString(char main[], char code[], int *tFactor, int *sFactor, int *amount)
{
	size_t i, j;
	int n, p;
	char copy[SIZE];
	int counter = *amount;
	for(i = 0; i < counter; i++)
	{
		for(j = 0; j < CODE; j++)
		{
			if(code[i] == main[j])
			{
				n = j - *tFactor;
				while(n < 0)
				{
					n = n + 37;
				}
				code[i] = main[n];
				copy[i] = main[n];
				break;
			}
		}
	}
		for(i = 0; i < counter; i++)
	{
		p = i - *sFactor;
		while(p < 0)
		{
			p = p + counter;
		}
		code[i] = copy[p];
	}
	return;
}

//encrypting the user's input
void encryptString(char main[], char code[], int *tFactor, int *sFactor, int *amount)
{
	size_t i, j;
	char copy[SIZE];
	int n, p;
	int counter = 0;
	for(i = 0; i < SIZE; i++)
	{
		if(code[i] != '\n')
		{
			counter++;
		}
		else if(code[i] == '\n')
		{
			break;
		}
	}
	*amount = counter;
	for(i = 0; i < counter; i++)
	{
		for(j = 0; j < CODE; j++)
		{
			if(code[i] == main[j])
			{
				n = j + *tFactor;
				while(n >= 37)
				{
					n = n - 37;
				}
				code[i] = main[n];
				copy[i] = main[n];
				break;
			}
		}
	}
	for(i = 0; i < counter; i++)
	{
		p = i + *sFactor;
		while(p >= counter)
		{
			p = p - counter;
		}
		code[i] = copy[p];
	}
	return;
}

//user's input
void getData(char code[], int *tFactor, int *sFactor)
{
	puts("Input the string to be encrypted:");
	fgets(code, SIZE, stdin); 
	puts("\nInput the transform factor:");
	scanf("%d", tFactor);
	puts("\nInput the shift factor:");
	scanf("%d", sFactor);
	return;
}
/*

Input the string to be encrypted:
brian tong

Input the transform factor:
4

Input the shift factor:
7

The encrypted string is: srkfvmerdx

The decrypted string is: brian tong

Press any key to continue . . .

*/


