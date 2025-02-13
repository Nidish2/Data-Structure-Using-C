#include <stdio.h>
#include <string.h>

int PM_subString(char s[], char p[])
{
    int max = strlen(s) - strlen(p) + 1, pos = -1;
    for (int i = 0; i < max; i++)
    { // strncmp() is used to compare the first n characters of two strings
        if (strncmp(s + i, p, strlen(p)) == 0)
        { //"s+i" ='s' is points to 's[0]' and "s+i" to s[0+i];
            pos = i;
            break;
        }
    }
    return pos;
}

int main()
{
    char s[] = "This test is a true pattern searching test";
    char p[] = "test";
    int position = PM_subString(s, p);
    if (position != -1)
        printf("Pattern found at position: %d\n", position);
    else
        printf("Pattern not found\n");
    return 0;
}