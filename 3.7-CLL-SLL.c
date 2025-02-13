#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *start = NULL, *current = NULL;

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
    }
    else
    {
        newnode->next = start;
        current->next = newnode;
        current = newnode;
    }
}

void insert_front()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d", &newnode->data);
    if (start == NULL)
    {
        start = newnode;
        current = newnode;
        newnode->next = start;      
    }
    else
    {
        newnode->next = start;
        start = newnode;
        current->next = start;      //important;
    }
}
void insert_position()
{
    int pos, i;
    struct node *newnode, *temp = start;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    if (start == NULL)
    {
        start = newnode;
        current = newnode;
        newnode->next = start;
    }
    else
    {
        printf("Enter the position : ");
        scanf("%d", &pos);

        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void display()
{
    struct node *newnode, *temp = start;
    if (start == NULL)
    {
        printf("Circular Single linked list is empty\n");
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

void delete_front()
{
    struct node *temp = start;
    if (start == NULL)
    {
        printf("Circular Single linked list is empty\n");
    }
    else
    {
        start = start->next;
        printf("Deleted element is %d\n", temp->data);
        current->next = start;

        free(temp);
    }
}

void delete_rear()
{
    struct node *temp = start, *temp1 = NULL;
    if (start == NULL)
    {
        printf("Circular Single linked list is empty\n");
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
        printf("Circular Single linked list is empty\n");
    }
    else
    {
        printf("Enter the position : ");
        scanf("%d", &pos);

        for (i = 1; temp != start && i < pos; i++)
        {
            temp1 = temp;
            temp = temp->next;
        }
        printf("Deleted element at the position %d is %d\n", pos, temp->data);
        temp1->next = temp->next;
        free(temp);
    }
}

void main()
{
    int choice;
    while (1)
    {
        printf("Enter \n1 : Create Node \n2 : Insert @ front \n3 : Insert @ position \n4 : Delete @ front \n5 : delete @ rear \n6 : Delete @ position\n7 : Display \n8 : Exit \n");
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
            display();
            break;

        case 8:
            exit(0);

        default:
            printf("Invalid Choice\n");
        }
    }
}