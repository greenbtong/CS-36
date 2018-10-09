//Area caculator 
#include <stdio.h>

// Function prototypes.
void calcAreaCircle();
void calcAreaRectangle();
void calcAreaTriangle();

//Options
int main(void)
{
	int option;
	printf("Choose the shape whose area you would like to compute:\n");
	printf("1- Circle, 2-Rectangle, 3- Triangle, 4- To quit the program: ");
	scanf("%d", &option);
	while(option != 4)
	{
		if(option == 1)
		{
			calcAreaCircle();	
		}
		else if(option == 2)
		{
			calcAreaRectangle();
		}
		else if(option == 3)
		{
			calcAreaTriangle();
		}
		printf("Choose the shape whose area you would like to compute:\n");
		printf("1- Circle, 2-Rectangle, 3- Triangle, 4- To quit the program: ");
		scanf("%d", &option);
	}
	return 0;
}

//area of a circle
void calcAreaCircle()
{
	int radius; 
	float area;
	printf("\nEnter the radius of the circle: ");
	scanf("%d", &radius);
	area = (float) 3.14 * radius * radius;
	printf("Area of a circle with radius %d is %.1f sq. units. \n\n", radius, area);
}

//area of a rectangle
void calcAreaRectangle()
{
	int Rheight;
	int Rwidth; 
	int area;
	printf("\nEnter the height and width of the rectangle: ");
	scanf("%d %d", &Rheight, &Rwidth);
	area = Rheight * Rwidth;
	printf("Area of a rectangle with height %d and width %d is %d sq. units.\n\n", Rheight, Rwidth, area);
}

//area of a triangle
void calcAreaTriangle()
{
	int Tbase;
	int Theight;
	float areaT;
	printf("\nEnter the base and height of the triangle: ");
	scanf("%d %d", &Tbase, &Theight);
	areaT = (float) 1/2 * Tbase * Theight;
	printf("Area of a triangle with base %d and height %d is %.0f sq. units.\n\n", Tbase, Theight, areaT);
}

/*
Choose the shape whose area you would like to compute:
1- Circle, 2-Rectangle, 3- Triangle, 4- To quit the program: 1

Enter the radius of the circle: 5
Area of a circle with radius 5 is 78.5 sq. units.

Choose the shape whose area you would like to compute:
1- Circle, 2-Rectangle, 3- Triangle, 4- To quit the program: 2

Enter the height and width of the rectangle: 5 6
Area of a rectangle with height 5 and width 6 is 30 sq. units.

Choose the shape whose area you would like to compute:
1- Circle, 2-Rectangle, 3- Triangle, 4- To quit the program: 3

Enter the base and height of the triangle: 9 4
Area of a triangle with base 9 and height 4 is 18 sq. units.

Choose the shape whose area you would like to compute:
1- Circle, 2-Rectangle, 3- Triangle, 4- To quit the program: 4
Press any key to continue . . .
*/
