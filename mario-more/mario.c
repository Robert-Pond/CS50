#include <cs50.h>
#include <stdio.h>

void printSpaces(int num);
void printHashes(int num);

int main(void)
{
    int height = 0;

    // ensures height is between 1 and 8
    while (height > 8 || height < 1)
    {
        height = get_int("Height: ");
    }

    // tracker for number of spaces to print
    int spaces = height - 1;

    // tracker for number of hashses to print
    int hashes = 1;

    for (int i = 0; i < height; i++)
    {
        printSpaces(spaces);
        printHashes(hashes);
        printf("  ");
        printHashes(hashes);
        printf("\n");
        spaces--;
        hashes++;
    }
}

// It prints spaces of given num
void printSpaces(int num)
{
    for (int i = 0; i < num; i++)
    {
        printf(" ");
    }
}

// It prints hashes of given num
void printHashes(int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("#");
    }
}