#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int size = 0, arr[30];
typedef struct node *Node;
Node root = NULL;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size)
{
int i;
for (i = 0; i < size; i++)
printf("%d ", arr[i]);
printf("\n");
}

void heapify(int arr[], int size, int i)
{
    int extreme = i;    //Parent
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < size && arr[leftChild] > arr[extreme])
    {
        extreme = leftChild;
    }

    if (rightChild < size && arr[rightChild] > arr[extreme])
    {
        extreme = rightChild;
    }

    if (extreme != i)
    {
        swap(&arr[i], &arr[extreme]);
        heapify(arr, size, extreme);
    }
}

void insert(int arr[], int nn)
{
    if (size == 0)
    {
        arr[size++] = nn;
    }
    else
    {
        arr[size++] = nn;
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(arr, size, i);
        }
    }
}

int deleteMax(int arr[], int *size)
{
    if (*size == 0)     //Check if the heap is empty
    {
        return -1;
    }
    else
    {
        int temp = arr[0];      // Save the value of the maximum element (root of the max heap)
        arr[0] = arr[*size - 1];        // Replace the root with the last element in the heap
        (*size)--;      // Decrease the size of the heap
        heapify(arr, *size, 0);      // Restore the heap property by heapifying from the root
        return temp;        // Return the value of the deleted maximum element       
    }
}

int main()
{
    int n;
    printf("Enter total number of elements: ");
    scanf("%d", &n);
    printf("Enter the %d elements \n", n);
    for (int i = 0; i < n; i++)
    {
        int nn;
        scanf("%d", &nn);
        insert(arr, nn);
    }
    int min, max;
    printf("The elements of Max Heap are \n");
    printArray(arr, size);
    // for (int i = 0; i < n; i++)
    // {
    //     if (i == 0)
    //     {
    //         max = deleteMax(arr, &size);
    //         printf("%d\t", max);
    //     }

    //     else if (i == n - 1)
    //     {
    //         min = deleteMax(arr, &size);
    //         printf("%d\t", min);
    //     }
    //     else
    //     {
    //         printf("%d\t", deleteMax(arr, &size));
    //     }
    // }
    printf("\n");
    printf("Max = %d",arr[0]);
    // printf("Minimum element is %d\n", min);
    // printf("Maximum element is %d\n", max);
    return 0;
}