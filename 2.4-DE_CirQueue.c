#include <stdio.h>
#include <stdlib.h>

int front = 0, rear = -1, queue[30], max, count = 0;

void enqueue_rear(int data)
{
    rear = (rear + 1) % max;
    queue[rear] = data;
    count++;
    printf("Rear=%d\n", rear);
}

void enqueue_front(int data)
{
    front = (front - 1) % max;
    queue[front] = data;
    count++;
    printf("Front=%d\n", front);
}

int dequeue_front()
{
    count--;
    int data = queue[front];
    front = (front + 1) % max;
    if (count == 0)
    {
        front = 0;
        rear = -1;
    }
    return data;
}

int dequeue_rear()
{
    count--;
    int data = queue[rear];
    rear = (rear - 1) % max;
    if (count == 0)
    {
        rear = -1;
        front = 0;
    }
    return data;
}

void display()
{
    printf("front=%d\n", front);
    printf("Rear=%d\n", rear);
    printf("The elements are : ");
    int data = 0, i = front;
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
        printf("Enter \n1 : Enqueue @ rear \n2 : Enqueue @ front\n3 : Dequeue @ front\n4 : Dequeue @ rear \n5 : Display \n6 : Exit \n");
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
                enqueue_rear(data);
            }
            break;

        case 2:
            if (front > 0 && count < max)
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
            if (count <= 0)
            {
                printf("Queue underflow\n");
            }
            else
            {
                printf("Dequeued element is %d \n", dequeue_front());
                printf("Front=%d\n", front);
            }
            break;

        case 4:
            if (count <= 0)
            {
                printf("Queue underflow\n");
            }
            else
            {
                printf("Dequeued element is %d \n", dequeue_rear());
                printf("Rear=%d\n", rear);
            }
            break;

        case 5:
            if (count <= 0)
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