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
        start = newnode;
        current = newnode;
    }
    else
    {
        newnode->prev = current;
        current->next = newnode;
        current = newnode;
    }
}

void insert_front()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
    if (start == NULL)
    {
        start = newnode;
        current = newnode;
    }
    else
    {
        newnode->next = start;
        start->prev = newnode;
        start = newnode;
    }
}
void insert_position()
{
    int pos, i;
    struct node *newnode, *temp = start, *temp1 = NULL;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
    if (start == NULL)
    {
        start = newnode;
        current = newnode;
    }
    else
    {
        printf("Enter the position : ");
        scanf("%d", &pos);

        for (i = 1; i < pos - 1; i++)
        {
            temp1 = temp;
            temp = temp->next;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void display_forward()
{
    struct node *newnode, *temp = start;
    if (start == NULL)
    {
        printf("Single linked list is empty\n");
    }
    else
    {
        printf("The elements are : ");
        while (temp != NULL)
        {
            printf("%d-> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void display_reverse()
{
    struct node *newnode, *temp = current;
    if (start == NULL)
    {
        printf("Double linked list is empty\n");
    }
    else
    {
        printf("The elements in reverse order are : ");
        while (temp != NULL)
        {
            printf("%d<- ", temp->data);
            temp = temp->prev;
        }
        printf("%d<- \n", temp->data);
        getchar();
        getchar();
    }
}

void delete_front()
{
    struct node *temp = start;
    if (start == NULL)
    {
        printf("Double linked list is empty\n");
    }
    else
    {
        start = start->next;
        start->prev = NULL;
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
    else
    {
        while (temp->next != NULL)
        {
            temp1 = temp;
            temp = temp->next;
        }
        printf("Deleted element is %d\n", temp->data);
        temp1->next = NULL;
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
        printf("Double linked list is empty\n");
    }
    else
    {
        printf("Enter the position : ");
        scanf("%d", &pos);

        for (i = 1; temp != NULL && i < pos; i++)
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

/*
Modified

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
*/