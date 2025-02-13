#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next,*prev;
} Node;
Node *s = NULL;

Node *createnode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
Node *insertEnd(Node *s, int data)
{
    Node *nn = createnode(data);
    if (s == NULL)
    {
        s = nn;
    }
    else
    {
        Node *temp = s;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = nn;
        nn->prev = temp;
    }
    return s;
}

Node *insertFront(Node *s, int data)
{
    Node *nn = createnode(data);
    if (s == NULL)
    {
        s = nn;
    }
    else
    {
        nn->next = s;
        s->prev = nn;
        s = nn;
    }
    return s;
}

Node *insertPos(Node *s, int pos, int data)
{
    Node *nn = createnode(data);
    if (s == NULL)
    {
        s = nn;
    }
    else
    {
        Node *p = s;
        for (int i = 1; i < pos - 1; i++)
        {
            p = p->next;
        }
        nn->next = p->next;
        nn->prev = p;
        p->next = nn;
    }
    return s;
}

Node *deleteEnd(Node *s)
{
    if (s == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        Node *temp = s, *temp1;
        while (temp->next != NULL)
        {
            temp1 = temp;
            temp = temp->next;
        }
        printf("The deleted element is %d", temp->data);
        temp1->next = NULL;
        temp->prev=NULL;
    }

    return s;
}

Node *deleteFront(Node *s)
{
    if (s == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("The deleted element is %d", s->data);
        s = s->next;
        s->prev = NULL;
    }
    return s;
}

Node *deletePos(Node *s, int pos)
{
    if (s == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        Node *temp = s, *temp1;
        for (int i = 1; i < pos; i++)
        {
            temp1 = temp;
            temp = temp->next;
        }
        printf("The deleted element is %d", temp->data);
        temp1->next = temp->next;
        temp->prev = NULL;
    }
    return s;
}

void display(Node *s)
{
    Node *temp = s;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main()
{
    int choice, data, pos;
    while (1)
    {
        printf("Enter \n1 : Insert @ rear \n2 : Insert @ front \n3 : Insert @ position \n4 : Delete @ front \n5 : delete @ rear \n6 : Delete @ position\n7 : Display \n8 : Exit \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            s = insertEnd(s, data);
            break;

        case 2:
            printf("Enter the data: ");
            scanf("%d", &data);
            s = insertFront(s, data);
            break;

        case 3:
            printf("Enter the position : ");
            scanf("%d", &pos);
            printf("Enter the data: ");
            scanf("%d", &data);
            s = insertPos(s, pos, data);
            break;

        case 4:
            s = deleteFront(s);
            break;

        case 5:
            s = deleteEnd(s);
            break;

        case 6:
            printf("Enter the position : ");
            scanf("%d", &pos);
            s = deletePos(s, pos);
            break;

        case 7:
            display(s);
            break;

        case 8:
            exit(0);

        default:
            printf("Invalid Choice\n");
        }
    }
}