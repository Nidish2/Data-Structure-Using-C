// Brute force pattern matching algorithm
// This is to find the First Occurrence of a pattern in a string.

#include <stdio.h>
#include <string.h>

int bf(char s[], char p[])
{
    int max = strlen(s) - strlen(p) + 1, pos = -1;
    for (int i = 0; i < max; i++)
    {
        int matched = 1;
        for (int j = 0; j < strlen(p); j++)
        {
            if (p[j] != s[i + j])
            {
                matched = 0;
                break; // Break if mismatch is found
            }
        }
        if (matched) // Check if pattern matched completely
        {
            pos = i; // it will return the position of the first occurrence of the pattern in the string
            break;   // If found, break out of outer loop
        }
    }
    return pos;
}

int main()
{
    char s[] = "This test is a true pattern searching test";
    char p[] = "test";
    int position = bf(s, p);
    if (position != -1)
        printf("Pattern found at position: %d\n", position);
    else
        printf("Pattern not found\n");
    return 0;
}
