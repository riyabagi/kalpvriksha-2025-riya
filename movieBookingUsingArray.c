#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct movieTickeet
{
    char movieName[MAX];
    int screenType;
    int seatNumber;
    int amount;
    char status[15];
} movie;

void displayBooked(movie bookings[], int front, int rear)
{
    if (front == rear + 1)
    {
        printf("No booking to display\n");
        return;
    }

    for (int index = front; index <= rear; index++)
    {
        printf("Movie Name: %s Screen Type: %d Seat Number: %d Amount: %d Status: %s\n", bookings[index].movieName, bookings[index].screenType, bookings[index].seatNumber,
               bookings[index].amount, bookings[index].status);
    }
    printf("\n");
}

void displayAproved(movie bookings[], int size)
{
    if (size < 0)
    {
        printf("No booking to approve");
        return;
    }

    for (int index = 0; index <= size; index++)
    {
        printf("Movie Name: %s Screen Type: %d Seat Number: %d Amount: %d Status: %s\n", bookings[index].movieName, bookings[index].screenType, bookings[index].seatNumber,
               bookings[index].amount, bookings[index].status);
    }
    printf("\n");
}

int main()
{
    int choice = 1, approvedIndex = -1;
    int front = 0, rear = -1;
    movie booking[MAX];
    movie approved[MAX];

    while (choice != 5)
    {
        printf("Enter the choice\t");
        scanf("%d", &choice);
        char movieName[MAX], status[] = "pending";
        int screenType, amount, seatNumber;
        switch (choice)
        {
        case 1:
            printf("Movie Name\t");
            getchar();
            scanf("%[^\n]s", movieName);
            printf("Screen\t");
            scanf("%d", &screenType);
            printf("Seat Number\t");
            scanf("%d", &seatNumber);
            printf("Amount\t");
            scanf("%d", &amount);
            rear++;
            strcpy(booking[rear].movieName, movieName);
            booking[rear].screenType = screenType;
            booking[rear].seatNumber = seatNumber;
            booking[rear].amount = amount;
            strcpy(booking[rear].status, status);
            break;

        case 2:
            if (front > rear)
            {
                printf("No pending bookings to approve.\n");
                break;
            }
            approvedIndex++;
            strcpy(approved[approvedIndex].movieName, booking[front].movieName);
            approved[approvedIndex].screenType = booking[front].screenType;
            approved[approvedIndex].seatNumber = booking[front].seatNumber;
            approved[approvedIndex].amount = booking[front].amount;
            strcpy(approved[approvedIndex].status, "approved");
            front++;
            break;

        case 3:
            displayBooked(booking, front, rear); // booked
            break;

        case 4:
            displayAproved(approved, approvedIndex); // approved
            break;

        case 5:
            printf("Exiting...");
            return 1;
            break;

        default:
            break;
        }
    }
    return 0;
}
