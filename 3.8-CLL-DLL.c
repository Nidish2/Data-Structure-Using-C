#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *start = NULL, *current = NULL;

void create_node()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
    if (start == NULL)
    {
        newnode->next = newnode;
        newnode->prev = newnode;
        start = newnode;
        current = newnode;
    }
    else
    {
        newnode->prev = current;
        newnode->next = start;
        current->next = newnode;
        start->prev = newnode;
        current = newnode;
    }
}

void insert_front()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    if (start == NULL)
    {
        newnode->next = start;
        newnode->prev = start;
        start = newnode;
        current = newnode;
    }
    else
    {
        newnode->prev = current;
        newnode->next = start;
        start->prev = newnode;
        start = newnode;
        current->next = start; // imp;
    }
}
void insert_position()
{
    int pos, i;
    struct node *newnode, *temp = start, *temp1 = start;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    if (start == NULL)
    {
        newnode->next = start;
        newnode->prev = start;
        start = newnode;
        current = newnode;
    }
    else
    {
        printf("Enter the position : ");
        scanf("%d", &pos);

        for (i = 1; i < pos; i++)
        {
            temp1 = temp;
            temp = temp->next;
        }
        newnode->prev = temp1;
        newnode->next = temp;
        temp1->next = newnode;
        temp->prev = newnode;
    }
}
void display_forward()
{
    struct node *newnode, *temp = start;
    if (start == NULL)
    {
        printf("Circular double linked list is empty\n");
    }
    else
    {
        printf("The elements are : ");
        do
        {
            printf("%d-> ", temp->data);
            temp = temp->next;

        } while (temp != start);
        printf("\n");
    }
}

void display_reverse()
{
    struct node *newnode, *temp = current;
    if (start == NULL)
    {
        printf("Circular Double linked list is empty\n");
    }
    else
    {
        printf("The elements in the reverse order are : ");
        do
        {
            printf("%d<- ", temp->data);
            temp = temp->prev;
        } while (temp != start);
        printf("%d ", temp->data);
        printf("\n");
    }
}

void delete_front()
{
    struct node *temp = start;
    if (start == NULL)
    {
        printf("Circular Double linked list is empty\n");
    }
    if (start->next == start)
    {
        start = current = NULL;
        printf("Deleted element is %d\n", temp->data);
    }
    else
    {
        start = start->next;
        start->prev = current;
        current->next = start;

        printf("Deleted element is %d\n", temp->data);
        free(temp);
    }
}

void delete_rear()
{
    struct node *temp = start, *temp1 = NULL;
    if (start == NULL)
    {
        printf("Double linked list is empty\n");
    }
    if (start->next = start)
    {
        start = current = NULL;
        printf("Deleted element is %d\n", temp->data);
    }
    else
    {
        while (temp->next != start)
        {
            temp1 = temp;
            temp = temp->next;
        }
        printf("Deleted element is %d\n", temp->data);
        temp1->next = start;
        start->prev = temp1;
        current = temp1;
        free(temp);
    }
}

void delete_position()
{
    struct node *temp = start, *temp1 = NULL;
    int i, pos;
    if (start == NULL)
    {
        printf("Circular Double linked list is empty\n");
    }
    else
    {
        printf("Enter the position : ");
        scanf("%d", &pos);
        if (pos < 1)
        {
            printf("Invalid position\n");
        }

        for (i = 1; i < pos; i++)
        {
            temp1 = temp;
            temp = temp->next;

            if (temp == start)
            {
                printf("Invalid position\n");
            }
        }
        printf("Deleted element at the position %d is %d\n", pos, temp->data);
        temp1->next = temp->next;
        if (temp == start)
        {
            start = start->next;
            start->prev = temp1;
            current = temp1;
        }
        free(temp);
    }
}

void main()
{
    int choice;
    while (1)
    {
        printf("Enter \n1 : Create Node \n2 : Insert @ front \n3 : Insert @ position \n4 : Delete @ front \n5 : delete @ rear \n6 : Delete @ position\n7 : Display from Beginning \n8 : Display from last \n9 : Exit \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create_node();
            break;

        case 2:
            insert_front();
            break;

        case 3:
            insert_position();
            break;

        case 4:
            delete_front();
            break;

        case 5:
            delete_rear();
            break;

        case 6:
            delete_position();
            break;

        case 7:
            display_forward();
            break;

        case 8:
            display_reverse();
            break;
        case 9:
            exit(0);

        default:
            printf("Invalid Choice\n");
        }
    }
}