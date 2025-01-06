#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ROWS 10
#define MAX_COLS 101

char customised_toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c; 
}

int startsWithVowel(char name[]) {
    char firstChar = customised_toLower(name[0]); 
    return (firstChar == 'a' || firstChar == 'e' || firstChar == 'i' || firstChar == 'o' || firstChar == 'u');
}

int customised_strlen(const char *str) {
    int length = 0;
    
    while (str[length] != '\0') {
        length++; 
    }
    
    return length;  
}

void customised_strcpy(char dest[], const char src[]) {
    int i = 0;
    
    while (src[i] != '\0') {
        dest[i] = src[i];  
        i++;
    }
    
    dest[i] = '\0';
}

int main() {
    int rows, cols;
    char names[MAX_ROWS][MAX_COLS][MAX_NAME_LENGTH]; 
    int vowelCount = 0;
    char longestNames[MAX_ROWS * MAX_COLS][MAX_NAME_LENGTH]; 
    int longestNameCount = 0;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    if (rows < 1 || rows > MAX_ROWS || cols < 1 || cols > MAX_COLS) 
    {
        printf("Invalid number of rows or columns.\n");
        return 1;
    }

    printf("Enter the names:\n");
    for (int rowIndex = 0; rowIndex < rows; rowIndex++) 
    {
        for (int colIndex = 0; colIndex < cols; colIndex++) 
        {
            printf("Name at (%d,%d): ", rowIndex, colIndex);
            scanf("%s", names[rowIndex][colIndex]);

            if (startsWithVowel(names[rowIndex][colIndex])) 
            {
                vowelCount++;
            }

            if (customised_strlen(names[rowIndex][colIndex]) > customised_strlen(longestNames[0])) 
            {
                customised_strcpy(longestNames[0], names[rowIndex][colIndex]);
                longestNameCount = 1;
            } 
            else if (customised_strlen(names[rowIndex][colIndex]) == customised_strlen(longestNames[0])) 
            {
                customised_strcpy(longestNames[longestNameCount], names[rowIndex][colIndex]);
                longestNameCount++;
            }
        }
    }

    printf("\nThe 2D array of names is:\n");
    for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
        for (int colIndex = 0; colIndex < cols; colIndex++) {
            printf("%s ", names[rowIndex][colIndex]);
        }
        printf("\n");
    }

    printf("\nNumber of names starting with a vowel: %d\n", vowelCount);

    printf("The longest names are:\n");
    for (int index = 0; index < longestNameCount; index++) {
        printf("%s\n", longestNames[index]);
    }

    return 0;
}
