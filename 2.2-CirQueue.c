#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1, queue[30], max, count = 0;

void enqueue(int data)
{
    rear = (rear + 1) % max;
    queue[rear] = data;
    count++;
}

int dequeue()
{
    count--;
    front = (front + 1) % max;
    int data = queue[front];
    if (count == 0)
    {
        front = rear = -1;
    }
    return data;
}

void display()
{
    printf("The elements are : ");
    int data = 0, i = (front + 1) % max;
    while (data < count)
    {
        printf("%d\t", queue[i]);
        i = (i + 1) % max;
        data++;
    }
    printf("\n");
}

int main()
{
    printf("Enter the size of the Queue: ");
    scanf("%d", &max);
    int choice, data;
    while (1)
    {
        printf("Enter \n1 : Enqueue\n2 : Dequeue \n3 : Display \n4 : Exit \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (count >= max)
            {
                printf("Queue overflow\n");
            }
            else
            {
                printf("Enter the data : ");
                scanf("%d", &data);
                enqueue(data);
            }
            break;

        case 2:
            if (count <= 0)
            {
                printf("Queue underflow\n");
            }
            else
            {
                printf("Dequeued element is %d \n", dequeue());
            }
            break;

        case 3:
            if (count <= 0)

            {
                printf("Queue underflow\n");
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