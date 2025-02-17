// 4. Movie Rating System
// You are designing a movie rating system where users can rate movies, update their ratings, and get
// the highest-rated movie.
// • "RATE <movie> <rating>" → Adds or updates the rating for the given movie (1 ≤ rating ≤ 10).
// • "REMOVE <movie>" → Removes the rating for the given movie, if it exists.
// • "TOP" → Returns the movie with the highest rating. If there are multiple, return the one that
// was rated first.
// Input:
// The first line contains an integer n (1 ≤ n ≤ 100) — the number of commands.
// The next n lines contain a command of one of the following types:
// • "RATE <movie> <rating>"
// • "REMOVE <movie>"
// • "TOP"
// Output:
// For each "TOP" command, print the movie with the highest rating. If no movies have been rated,
// print "No movies rated".

#include <stdio.h>
#include <string.h>

#define MAX 100

typedef enum
{
    GiveRatings = 1,
    RemoveRating,
    HighestRating,
    Exit
} op;

typedef struct movieRatingSystem
{
    int top;
    char movie[MAX][50];
    float rating[MAX];
} stack;

void pushItem(stack *s, char movie[], float rating)
{
    if (s->top == MAX-1)
    {
        printf("Stack overflow\n");
        return;
    }

    for (int index = 0; index <= s->top; index++)
    {
        if (strcmp(movie, s->movie[index]) == 0)
        {
            s->rating[index] = rating;
            return;
        }
    }

    s->top++;
    strcpy(s->movie[s->top], movie);
    s->rating[s->top] = rating;
}

void RemoveRatings(stack *s, char movie[])
{
    if (s->top == -1)
    {
        printf("Stack UnderFlow\n");
        return;
    }

    for (int index = 0; index <= s->top; index++)
    {
        if (strcmp(movie, s->movie[index]) == 0)
        {
            s->rating[index] = 0;
            return;
        }
    }

    printf("Movie not found\n");
}

void highRatedMovie(stack s)
{
    if (s.top == -1)
    {
        printf("No movies\n");
        return;
    }

    int highestRate = s.rating[s.top];
    char highMovie[MAX];
    strcpy(highMovie, s.movie[s.top]);

    for (int index = 0; index <= s.top; index++)
    {
        if (s.rating[index] > highestRate)
        {
            highestRate = s.rating[index];
            strcpy(highMovie, s.movie[index]);
        }
    }

    printf("%s %d\n",highMovie, highestRate);
}

int main()
{
    stack s;
    s.top = -1;
    int choice = 0;
    float rating;
    char movie[MAX];

    printf("1]Give Ratings\n2]Remove Rating\n3]HighestRating\n4]Exit\n");

    while (choice != 4)
    {
        printf("Enter the choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case GiveRatings:
            printf("Enter the movie:  ");
            scanf("%s", movie);
            printf("Enter the rating of the movie:  ");
            scanf("%f", &rating);
            pushItem(&s, movie, rating);
            break;

        case RemoveRating:
            printf("Enter the movie:  ");
            scanf("%s", movie);
            RemoveRatings(&s, movie);
            break;

        case HighestRating:
            highRatedMovie(s);
            break;

        case Exit:
            printf("Exiting...\n");
            return 0;
            break;

        default:
            break;
        }
    }

    return 0;
}