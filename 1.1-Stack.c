// Stack of integers

// #include <stdio.h>
// #include <stdlib.h>
// int top = -1, max, stack[30];

// void push(int data)
// {
//     stack[++top] = data;
// }

// int pop()
// {
//     return stack[top--];
// }

// void display()
// {
//     printf("The elements are \n");
//     for (int i = top; i >= 0; i--)
//     {
//         printf("%d\n", stack[i]);
//     }
// }

// int main()
// {
//     printf("Enter the size of stack: ");
//     scanf("%d", &max);
//     int choice, data;
//     while (1)
//     {
//         printf("Enter \n1 : Push\n2 : Pop \n3 : Display \n4 : Exit \n");
//         scanf("%d", &choice);
//         switch (choice)
//         {
//         case 1:
//             if (top >= max - 1)
//             {
//                 printf("Stack overflow\n");
//             }
//             else
//             {
//                 printf("Enter the element : ");
//                 scanf("%d", &data);
//                 push(data);
//             }
//             break;

//         case 2:
//             if (top == -1)
//             {
//                 printf("Stack underflow\n");
//             }
//             else
//             {
//                 printf("The popped element is %d\n", pop());
//             }
//             break;

//         case 3:
//             if (top == -1)
//             {
//                 printf("Stack underflow\n");
//             }
//             else
//             {
//                 display();
//             }
//             break;

//         case 4:
//             exit(0);

//         default:
//             printf("Invalid Choice\n");
//         }
//     }
//     return 0;
// }

// Stack of characters
#include <stdio.h>
#include <stdlib.h>
int top = -1, max;
char stack[30];

void push(char data)
{
    stack[++top] = data;
}

char pop()
{
    return stack[top--];
}

void display()
{
    printf("The elements are \n");
    for (int i = top; i >= 0; i--)
    {
        printf("%c\n", stack[i]);
    }
}

int main()
{
    printf("Enter the size of stack: ");
    scanf("%d", &max);
    int choice, data;
    while (1)
    {
        printf("Enter \n1 : Push\n2 : Pop \n3 : Display \n4 : Exit \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (top >= max - 1)
            {
                printf("Stack overflow\n");
            }
            else
            {
                printf("Enter the element : ");
                scanf("%s", &data); // " %c" or "%s"    // Add space before %c to consume newline characters
                push(data);
            }
            break;

        case 2:
            if (top == -1)
            {
                printf("Stack underflow\n");
            }
            else
            {
                printf("The popped element is %c\n", pop());
            }
            break;

        case 3:
            if (top == -1)
            {
                printf("Stack underflow\n");
            }
            else
            {
                display();
            }
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}