#include <stdio.h>
#include <stdlib.h>

int front = 0, rear = 0, queue[30], max;

void enqueue(int data)
{
    queue[rear++] = data;
}

void insert_position(int position, int data)
{
    {
        for (int i = rear; i >= position - 1; i--)
        {
            queue[i + 1] = queue[i];
        }
        queue[position - 1] = data;
        rear++;
    }
}

void priority_queue(int data)
{
    int j = rear;
    while (j >= 0 && data < queue[j])
    {
        queue[j + 1] = queue[j];
        j--;
    }
    queue[j + 1] = data;
    rear++;
}

int dequeue()
{
    return queue[front++];
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
    int choice, data, position;
    while (1)
    {
        printf("Enter \n1 : Enqueue\n2 : Enqueue @ position\n3 : Priority Queue \n4 : Dequeue \n5 : Display \n6 : Exit \n");
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
                enqueue(data);
            }
            break;

        case 2:
            if (rear >= max)
            {
                printf("Queue overflow\n");
            }

            else
            {
                printf("Enter the position : ");
                scanf("%d", &position);
                if (position < 0 || position > max)
                {
                    printf("Invalid position\n");
                }
                else
                {
                    printf("Enter the data : ");
                    scanf("%d", &data);
                    insert_position(position, data);
                }
            }
            break;

        case 3:
            if (rear >= max)
            {
                printf("Queue overflow\n");
            }
            else
            {
                printf("Enter the data : ");
                scanf("%d", &data);
                priority_queue(data);
            }
            break;

        case 4:
            if (front >= rear)
            {
                printf("Queue underflow\n");
            }
            else
            {
                printf("Dequeued element is %d \n", dequeue());
            }
            break;

        case 5:
            if (front >= rear)
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