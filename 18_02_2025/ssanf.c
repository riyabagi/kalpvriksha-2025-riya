#include <stdio.h>
#include <string.h>

int main()
{
    // ----------------------------------------static/fixed number of words
    // char input[100], word1[100], word2[100];
    // printf("Enter the string\n");

    // fgets(input, sizeof(input), stdin);
    // sscanf(input, "%s %s", word1, word2);
    // printf("%s\n%s\n", word1, word2);

    // --------------------------------------------dynamic words

    char input[100], words[10];
    char *ptr;

    printf("Enter a string\n");
    fgets(input, 100, stdin);

    ptr = input;

    printf("Words in the string:\n");

    while (sscanf(ptr, "%s", words) == 1)
    {
        printf("%s\n", words);
        ptr += strlen(words) + 1;
    }

    // -----------------------------------Question on string parsing----------------------
    // "ID:101 Name:Alice Score:85, ID:102 Name:Bob Score:78, ID:103 Name:Charlie Score:92"

    // char input[200], word1[10], word2[10], word3[10];
    // char *ptr;

    // printf("Enter the string:\n");
    // fgets(input, 200, stdin);

    // ptr = input;

    // printf("Parsed words:\n");

    // while (sscanf(ptr, "ID:%s Name:%s Score:%s", word1, word2, word3) == 3)
    // {
    //     printf("ID: %s, Name: %s, Score: %s\n", word1, word2, word3);
    //     ptr += strlen(word1) + strlen(word2) + strlen(word3) + 19;
    // }

    return 0;
}