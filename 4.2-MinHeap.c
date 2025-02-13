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
    int smallest = i; // Parent
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < size && arr[leftChild] < arr[smallest])
    {
        smallest = leftChild;
    }

    if (rightChild < size && arr[rightChild] < arr[smallest])
    {
        smallest = rightChild;
    }

    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, size, smallest);
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
        for (int i = size / 2 - 1; i >= 0; i--) //size/2-1 imp;
        {
            heapify(arr, size, i);
        }
    }
}

int deleteMin(int arr[], int *size)
{
    if (*size == 0)
    {
        return -1;
    }
    else
    {
        int temp = arr[0];       // Save the value of the maximum element (root of the min heap)
        arr[0] = arr[*size - 1]; // Replace the root with the last element in the heap
        (*size)--;               // Decrease the size of the heap
        heapify(arr, *size, 0);  // Restore the heap property by heapifying from the root
        return temp;             // Return the value of the deleted minimum element
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
    printf("The elements of Min Heap \n");
    printArray(arr, size);
    // for (int i = 0; i < n; i++)
    // {
    //     if (i == 0)
    //     {
    //         min = deleteMin(arr, &size);
    //         printf("%d\t", min);
    //     }

    //     else if (i == n - 1)
    //     {
    //         max = deleteMin(arr, &size);
    //         printf("%d\t", max);
    //     }
    //     else
    //     {
    //         printf("%d\t", deleteMin(arr, &size));
    //     }
    // }
    printf("\n");
    printf("Min = %d",arr[0]);
    // printf("Minimum element is %d\n", min);
    // printf("Maximum element is %d\n", max);
    return 0;
}