//----------------------------------------------------------------------------//
// Name:    Brian Tong                                                                  //
// Student ID:  276042                                                              //
// Assignment:  4                                                              //
//----------------------------------------------------------------------------//

//calculating investment gain and sorting it from a file
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

//structure 
struct stocks
{
	char name[25];
	char symbol[6];
	float gain, price, year, increase;
};

//prototype
void readFile(struct stocks data[]);
void displayInfo(struct stocks ordered[]);
void rewriteFile(struct stocks ordered[]);
void bubblesort(struct stocks ordered[]);

//call other functions
int main(void)
{
	struct stocks data[1000];
	readFile(data);
	bubblesort(data);
	displayInfo(data);
	rewriteFile(data);
	return 0;
}

//sort the info
void bubblesort(struct stocks ordered[])
{
	int pass;
	struct stocks	temp;    
	size_t j;
	for(pass = 0; pass < 1000; pass++)
	{
		for(j = 0; j < 1000 - 1; j++)
		{
			if(ordered[j].gain < ordered[j + 1].gain)
			{
				temp = ordered[j+1];
				ordered[j+1] = ordered[j];
				ordered[j] = temp;
			}
		}
	}
	return;
}

//reading file
void readFile(struct stocks data[])
{
	int count = 0;
	char stockData[80];
	char *trash; 
	FILE *stocksFile;
	if((stocksFile = fopen("C:\\Users\\Brian Tong\\Desktop\\stocks.txt", "r")) == NULL)
	{
		puts("File could not be opened.");
	}
	else
	{
		fgets(stockData, 80, stocksFile);
		while(!feof(stocksFile))
		{
			trash = strtok(stockData, ",");
			strcpy(data[count].name, trash);

			trash = strtok(NULL, ",");
			strcpy(data[count].symbol, trash);
			
			trash = strtok(NULL, ",");
			data[count].price = (float) atof(trash);
			
			trash = strtok(NULL, ",");
			data[count].year = (float) atof(trash);
			
			trash = strtok(NULL, ",");
			data[count].increase = (float) atof(trash);
			
			data[count].gain = 25000 / data[count].price * data[count].year * (data[count].increase / 1000 + 1);
			count++;
			fgets(stockData, 80, stocksFile);
		}
	}
	fclose(stocksFile);
	return;
}

//top ten investment gains
void displayInfo(struct stocks ordered[])
{
	int i;
	printf("%-25s%-8s%-22s\n", "Stock Name", "Symbol", "Investment Gain ($)");
	for( i = 0; i < 10; i++)
	{
		printf("%-25s%-8s%.2f\n", ordered[i].name, ordered[i].symbol, ordered[i].gain);
	}
	return;
}

//display inputs into a file
void rewriteFile(struct stocks ordered[])
{
	int i;
	FILE *pFile;
	if((pFile = fopen("C:\\Users\\Brian Tong\\Desktop\\new.txt", "w")) == NULL)
	{
		puts("File could not be opened\n:");
	}
	else
	{
		fprintf(pFile, "%-25s%-8s%-22s\n", "Stock Name", "Symbol", "Investment Gain ($)");
		for( i = 0; i < 100; i++)
		{
			fprintf(pFile, "%-25s%-8s%.2f\n", ordered[i].name, ordered[i].symbol, ordered[i].gain);
		}
	}
	fclose(pFile);
	return;
}
/*

Stock Name               Symbol  Investment Gain ($)
ADTRAN Inc               ADTN    2209.27
EntreMed Inc             ENMD    2185.73
Blucora Inc              BCOR    1837.99
CME Group Inc            CME     1658.95
Preferred Bank           PFBC    1657.55
Landstar System Inc      LSTR    1472.11
Entegris Inc             ENTG    1447.43
Plumas Bancorp           PLBC    1430.49
Atmel Corporation        ATML    1389.02
Acxiom Corporation       ACXM    1382.38
Press any key to continue . . .

*/

