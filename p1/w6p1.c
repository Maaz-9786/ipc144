#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User Libraries
#include "w6p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* num)
{
	int a;
	do
	{
		scanf("%d", &a);
		if (a <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}

	} while (a <= 0);
	if (num != NULL)

		*num = a;
	return a;//return the variable a

}
// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* num)
{
	double a;
	do
	{
		scanf("%lf", &a);
		if (a <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}

	} while (a <= 0);
	if (num != NULL)

		*num = a;
	return a;//return the variable a

}




// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int num_product)
{

	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", num_product);
	printf("NOTE: A 'serving' is %dg\n", GRAMS);


}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequence_number)
{
	struct CatFoodInfo food = { 0 };
	printf("\nCat Food Product #%d\n", sequence_number);
	printf("--------------------\n");
	printf("SKU           : ");
	getIntPositive(&food.SKU);
	printf("PRICE         : $");
	getDoublePositive(&food.Price);
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&food.Weight);
	printf("CALORIES/SERV.: ");
	getIntPositive(&food.Calories);

	return food;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const int calories, const double* weight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);

}

// 7. Logic entry point
void start()
{
	struct CatFoodInfo cats[PRODUCT_QUALITY] = { {0} };
	openingMessage(PRODUCT_QUALITY);
	int i;
	for (i = 0; i < PRODUCT_QUALITY; i++)
	{
		cats[i] = getCatFoodInfo(i + 1);
	}
	printf("\n");
	displayCatFoodHeader();
	for (i = 0; i < PRODUCT_QUALITY; i++)
	{
		displayCatFoodData(cats[i].SKU, &cats[i].Price, cats[i].Calories, &cats[i].Weight);
	}
}