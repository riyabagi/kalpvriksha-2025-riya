// 3. Enum with Struct
// Question: Define a struct called Car with fields: brand (string) and type (enum with values SEDAN, SUV, HATCHBACK). Take user input for a car and print the details.

#include <stdio.h>

typedef enum
{
    sedan,
    suv,
    hatchback
} type;

typedef struct car
{
    char brand[20];
    type cartype;
} car;

void displayFunction(car car)
{
    const char *carTypes[] = {"SEDAN", "SUV", "HATCHBACK"};
    printf("Car Details:\n");
    printf("Brand: %s\n", car.brand);
    printf("Type: %s\n", carTypes[car.cartype]);
}

int main()
{
    car mycar;
    int inputType;

    printf("Enter the brand name\n");
    scanf("%s", mycar.brand);

    printf("Select car type (0: SEDAN, 1: SUV, 2: HATCHBACK):\n");
    scanf("%d", &inputType);

    mycar.cartype = (type)inputType;

    displayFunction(mycar);

    return 0;
}