#include <stdio.h>

typedef enum
{
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
} days;

const char *getDayString(int day)
{
    switch (day)
    {
    case SUNDAY:
        return "SUNDAY";
        break;
    case MONDAY:
        return "MONDAY";
        break;
    case TUESDAY:
        return "TUESDAY";
        break;
    case WEDNESDAY:
        return "WEDNESDAY";
        break;
    case THURSDAY:
        return "THURSDAY";
        break;
    case FRIDAY:
        return "FRIDAY";
        break;
    case SATURDAY:
        return "SATURDAY";
        break;

    default:
        break;
    }
}

int main()
{
    // days day = MONDAY;

    int day;
    printf("Enter the number\n");
    scanf("%d", &day);
    if (day < 0 || day > 6)
    {
        printf("Invalid day number\n");
        return 0;
    }
    printf("The day is %s ", getDayString(day));
    return 0;
}