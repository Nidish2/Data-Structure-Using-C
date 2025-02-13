#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create_node()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    return newnode;
}

struct node *create_list()
{
    struct node *start = NULL;
    struct node *current = NULL;

    int max;
    printf("Enter total numbers of nodes: ");
    scanf("%d", &max);

    for (int i = 1; i <= max; i++)
    {
        struct node *newnode = create_node();

        if (start == NULL)
        {
            start = newnode;
            current = newnode;
        }
        else
        {
            current->next = newnode;
            current = newnode;
        }
    }
    return start;
}

void display(struct node *start)
{
    struct node *temp = start;
    if (start == NULL)
    {
        printf("Single linked list is empty\n");
    }
    else
    {
        printf("The elements are: ");
        while (temp != NULL)
        {
            printf("%d-> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

struct node *merge_lists(struct node *list1, struct node *list2)
{
    struct node *temp = list1;

    if (list1 == NULL)
    {
        return list2;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = list2;

    return list1;
}

// Merging the two sorted linked lists.
//  before merging the two linked lists, It should be sorted, then this function holds good.
struct node *merge_lists_Sort(struct node *start1, struct node *start2)
{

    if (start1 == NULL)
    {
        return start2;
    }

    if (start2 == NULL)
    {
        return start1;
    }
    struct node *start = NULL, *merge_lists = NULL;
    if (start1->data < start2->data)
    {
        merge_lists = start1;
        start1 = start1->next;
    }
    else
    {
        merge_lists = start2;
        start2 = start2->next;
    }
    start = merge_lists;
    while ((start1 != NULL) && (start2 != NULL))
    {
        if (start1->data < start2->data)
        {
            merge_lists->next = start1;
            start1 = start1->next;
        }
        else
        {
            merge_lists->next = start2;
            start2 = start2->next;
        }
        merge_lists = merge_lists->next;
    }
    if (start1 != NULL)
    {
        merge_lists->next = start1;
    }
    else
    {
        merge_lists->next = start2;
    }
    return start;
}

int main()
{
    printf("Enter the elements of First SLL\n");
    struct node *start1 = create_list();
    printf("Enter the elements of Second SLL\n");
    struct node *start2 = create_list();

    printf("First SLL\n");
    display(start1);
    printf("Second SLL\n");
    display(start2);

    printf("Enter\n1. To just merge the two SLL\n2. To merge the two sorted SLL and make it Sorted\n");
    int choice;
    scanf("%d", &choice);
    struct node *mergedList=NULL, *mergedSortedList=NULL;
    switch (choice)
    {
    case 1:
        mergedList = merge_lists(start1, start2);
        printf("Merged SLL\n");
        display(mergedList);
        break;
    case 2:
        mergedSortedList = merge_lists_Sort(start1, start2);
        printf("Merged Sorted SLL\n");
        display(mergedSortedList);
        break;
    default:
        printf("Invalid Choice\n");
    }

    return 0;
}