#include <stdio.h>
#include <ctype.h>

char stack[20];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

int priority(char x)
{
    if (x == '(')
    {
        return 0;
    }
    else if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
    else if (x == '^')
    {
        return 3;
    }
    return 0;
}

int main()
{
    char exp[40], *e, x;
    printf("Enter the expresion: ");
    scanf("%s", exp);
    e = exp;
    while (*e != '\0')
    {
        if (isalnum(*e))
        {
            printf("%c", *e);
        }
        else if (*e == '(')
        {
            push(*e);
        }
        else if (*e == ')')
        {
            while ((x = pop()) != '(')
            {
                printf("%c", x);
            }
        }
        else
        {
            while (priority(*e) <= priority(stack[top]))
            {
                printf("%c", pop());
            }
            push(*e);
        }
        e++;
    }

    while (top != -1)
    {
        printf("%c", pop());
    }

    return 0;
}