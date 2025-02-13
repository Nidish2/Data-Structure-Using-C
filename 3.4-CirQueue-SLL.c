#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *start = NULL, *current = NULL;
int max, count;

void create_node()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (start == NULL)
    {
        start = newnode;
        current = newnode;
        newnode->next = start;
        count = 1;
    }
    else
    {
        newnode->next = start;
        current->next = newnode;
        current = newnode;
        count++;
    }
}

void delete_front()
{
    struct node *temp = start;
    if (start == NULL)
    {
        printf("Circular queue underflow\n");
        count = 0;
    }
    else
    {
        start = start->next;
        printf("Deleted element is %d\n", temp->data);
        current->next = start;
        count--;
        free(temp);
    }
}

void display()
{
    struct node *newnode, *temp = start;
    if (start == NULL)
    {
        printf("Circular queue underflow\n");
    }
    else
    {
        printf("The elements are : ");
        while (temp->next != start)
        {
            printf("%d-> ", temp->data);
            temp = temp->next;
        }
        printf("%d ", temp->data);
        printf("\n");
    }
}

void main()
{
    printf("Enter the size of Queue: ");
    scanf("%d", &max);
    int choice;
    while (1)
    {
        printf("Enter \n1 : Enqueue\n2 : Dequeue \n3 : Display \n4 : Exit \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (count >= max)
            {
                printf("Circular Queue overflow\n");
            }
            else
            {
                create_node();
            }
            break;

        case 2:
            if (count == 0)
            {
                printf("Circular queue underflow\n");
            }
            else
            {
                delete_front();
            }
            break;

        case 3:
            if (count == 0)
            {
                printf("Circular queue underflow\n");
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
}