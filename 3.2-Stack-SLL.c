#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *start = NULL, *current = NULL;
int count, max;

void insert_front()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->next = NULL;
    if (start == NULL)
    {
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        start = newnode;
        current = newnode;
        count = 1;
    }

    else
    {
        if (count > max)
        {
            printf("Stack overflow \n");
            return;
        }
        else
        {
            printf("Enter the data: ");
            scanf("%d", &newnode->data);
            newnode->next = start;
            start = newnode;
            count++;
        }
    }
}

void display()
{
    struct node *newnode, *temp = start;
    if (start == NULL)
    {
        printf("Stack is empty\n");
    }
    else if (count > max)
    {
        printf("Stack overflow\n");
    }
    else
    {
        printf("The elements on stack are : \n");
        while (temp != NULL)
        {
            printf("%d \n", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void delete_front()
{
    struct node *temp = start;
    if (start == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        start = start->next;
        printf("Deleted element is %d\n", temp->data);
        free(temp);
    }
}
void main()
{
    int max;
    printf("Enter the size of Stack: ");
    scanf("%d", &max);
    int choice;
    while (1)
    {
        printf("Enter \n1 : Push\n2 : Pop \n3 : Display \n4 : Exit \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_front();
            break;

        case 2:
            delete_front();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid Choice\n");
        }
    }
}