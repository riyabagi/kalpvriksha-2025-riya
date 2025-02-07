#include <stdio.h>

enum days
{
    monday, tuesday, wednesday, thursday, friday, saturday, sunday
};

int main()
{
    enum days today;
    today = thursday;
    printf("%d\n",today);
    return 0;
}