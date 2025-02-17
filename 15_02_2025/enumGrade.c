// Question: Create an enum for grades (A, B, C, D, F).
// Ask the user to enter a grade letter and display the corresponding description (e.g., A = Excellent, B = Good, etc.).

#include <stdio.h>

typedef enum
{
    A,
    B,
    C,
    D,
    F
} grades;

char *gradeReturn(char grad)
{
    switch (grad)
    {
    case 'A':
        return "Excellent";
        break;
    case 'B':
        return "Very Good";
        break;
    case 'C':
        return "Good";
        break;
    case 'D':
        return "Okay";
        break;
    case 'F':
        return "Fail";
        break;

    default:
        printf("Give valid input\n");
        break;
    }
}

int main()
{
    char grad;
    printf("Enter your grades\n");
    scanf("%c", &grad);

    printf("The grade is : %s",gradeReturn(grad));
    return 0;
}