#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ROWS 10
#define MAX_COLS 101

char customised_toLower(char character) 
{
    if (character >= 'A' && character <= 'Z') 
    {
        return character + 32;
    }
    return character; 
}

int startsWithVowel(char *name) 
{
    char firstChar = customised_toLower(*name); 
    return (firstChar == 'a' || firstChar == 'e' || firstChar == 'i' || firstChar == 'o' || firstChar == 'u');
}

int customised_strlen(const char *str) 
{
    int length = 0;
    while (*(str + length) != '\0') 
    {
        length++; 
    }
    return length;  
}

void customised_strcpy(char *dest, const char *src) 
{
    while (*src != '\0') 
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

void inputNames(char (*names)[MAX_COLS][MAX_NAME_LENGTH], int rows, int cols) 
{
    printf("Enter the names:\n");
    for (int row = 0; row < rows; row++) 
    {
        for (int col = 0; col < cols; col++) 
        {
            printf("Name at (%d,%d): ", row, col);
            scanf("%s", *(*(names + row) + col));
        }
    }
}

void printNames(char (*names)[MAX_COLS][MAX_NAME_LENGTH], int rows, int cols) 
{
    printf("\nThe 2D array of names is:\n");
    for (int row = 0; row < rows; row++) 
    {
        for (int col = 0; col < cols; col++) 
        {
            printf("%s ", *(*(names + row) + col));
        }
        printf("\n");
    }
}

int findLongestNames(char (*names)[MAX_COLS][MAX_NAME_LENGTH], int rows, int cols, char (*longestNames)[MAX_NAME_LENGTH]) 
{
    int longestNameCount = 0;
    int maxLength = 0;

    for (int row = 0; row < rows; row++) 
    {
        for (int col = 0; col < cols; col++) 
        {
            char *currentName = *(*(names + row) + col);
            int currentLength = customised_strlen(currentName);

            if (currentLength > maxLength) 
            {
                maxLength = currentLength;
                customised_strcpy(*longestNames, currentName);
                longestNameCount = 1;
            } 
            else if (currentLength == maxLength) 
            {
                customised_strcpy(*(longestNames + longestNameCount), currentName);
                longestNameCount++;
            }
        }
    }
    return longestNameCount;
}

void printLongestNames(char (*longestNames)[MAX_NAME_LENGTH], int longestNameCount) 
{
    printf("The longest names are:\n");
    for (int i = 0; i < longestNameCount; i++) 
    {
        printf("%s\n", *(longestNames + i));
    }
}

int main() 
{
    int rows, cols;
    char names[MAX_ROWS][MAX_COLS][MAX_NAME_LENGTH]; 
    char longestNames[MAX_ROWS * MAX_COLS][MAX_NAME_LENGTH]; 
    int vowelCount = 0;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    if (rows < 1 || rows > MAX_ROWS || cols < 1 || cols > MAX_COLS) 
    {
        printf("Invalid number of rows or columns.\n");
        return 1;
    }

    inputNames(names, rows, cols);

    for (int row = 0; row < rows; row++) 
    {
        for (int col = 0; col < cols; col++) 
        {
            if (startsWithVowel(*(*(names + row) + col))) 
            {
                vowelCount++;
            }
        }
    }

    int longestNameCount = findLongestNames(names, rows, cols, longestNames);

    printNames(names, rows, cols);

    printf("\nNumber of names starting with a vowel: %d\n", vowelCount);

    printLongestNames(longestNames, longestNameCount);

    return 0;
}
