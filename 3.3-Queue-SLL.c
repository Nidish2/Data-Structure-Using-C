#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *start = NULL, *current = NULL;
int count, max;

void create_node()
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
        {
            if (count >= max)
            {
                printf("Queue overflow\n");
            }
            else
            {

                printf("Enter the data: ");
                scanf("%d", &newnode->data);
                current->next = newnode;
                current = newnode;
                ++count;
            }
        }
    }
}

void delete_front()
{
    struct node *temp = start;
    if (start == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        start = start->next;
        printf("Deleted element is %d\n", temp->data);
        free(temp);
        count--;
    }
}

void display()
{
    struct node *newnode, *temp = start;
    if (start == NULL)
    {
        printf("Queue is empty\n");
    }
    else if (count > max)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        printf("The elements in Queue are : ");
        while (temp != NULL)
        {
            printf("%d \t", temp->data);
            temp = temp->next;
        }
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
            create_node();
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