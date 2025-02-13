#include <stdio.h>
#include <stdlib.h>

int front = 0, rear = 0, queue[30], max;

void enqueue_rear(int data)
{
    queue[rear++] = data;
}

void enqueue_front(int data)
{
    queue[--front] = data;
}

int dequeue_front()
{
    return queue[front++];
}

int dequeue_rear()
{
    return queue[--rear];
}

void display()
{
    int temp = front;
    printf("The elements are : ");
    while (temp < rear)
    {
        printf("%d\t", queue[temp++]);
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
        printf("Enter \n1 : Enqueue @ rear \n2 : Enqueue @ front\n3 : Dequeue @ front\n4 : Dequeue @ rear \n5 : Display \n6 : Exit \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (rear >= max)
            {
                printf("Queue overflow\n");
            }
            else
            {
                printf("Enter the data : ");
                scanf("%d", &data);
                enqueue_rear(data);
            }
            break;

        case 2:
            if (front > 0)
            {
                printf("Enter the data : ");
                scanf("%d", &data);
                enqueue_front(data);
            }
            else
            {
                printf("Enqueue at front is not possible\n");
            }
            break;

        case 3:
            if (front >= rear)
            {
                printf("Queue underflow\n");
            }
            else
            {
                printf("Dequeued element is %d \n", dequeue_front());
            }
            break;

        case 4:
            if (front >= rear)
            {
                printf("Queue underflow\n");
            }
            else
            {
                printf("Dequeued element is %d \n", dequeue_rear());
            }
            break;

        case 5:
            if (front >= rear || front <= -1 || rear <= -1)
            {
                printf("Queue underflow\n");
            }
            else
            {
                display();
            }
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid Choice\n");
        }
    }

    return 0;
}