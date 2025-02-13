#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int top = -1, stack[40];

void push(int data)
{
    stack[++top] = data;
}

int pop()
{
    return stack[top--];
}

int operation(int b, int a, char op)
{
    switch (op)
    {
    case '+':
        return b + a;
        break;

    case '-':
        return b - a;
        break;

    case '*':
        return b * a;
        break;

    case '/':
        return b / a;
        break;

    case '^':
        return pow(b, a); // Using pow() for exponentiation
        break;

    case '%':
        return b % a;
        break;

    default:
        printf("Invalid Operater\n"); 
    }
}

int main()
{
    char *e, exp[40];
    printf("Enter the postfix expression : ");
    scanf("%s", exp);
    e = exp;
    while (*e != '\0')
    {
        if (isdigit(*e))
        {
            push(*e - '0');
        }

        else if (*e == '+' || *e == '-' || *e == '*' || *e == '/' || *e == '^' || *e == '%')
        {
            int a = pop(), b = pop(), result = operation(b, a, *e);
            push(result);
        }
        e++;
    }
    if (top == 0)
    {
        printf("The result is %d\n", pop());
    }
    else
    {
        printf("Invalid postfix expresion\n");
    }

    return 0;
}