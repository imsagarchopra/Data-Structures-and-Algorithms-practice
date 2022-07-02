#include <stdio.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

void Swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void Append(struct Array *arr, int n)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = n;
    }

}

void Insert(struct Array* arr, int index, int n)
{
    if (index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }

        arr->A[index] = n;
        arr->length++;
    }

}

int Delete(struct Array* arr, int index)
{
    if (index >= 0 && index < arr->length)
    {
        int x = arr->A[index];
        for (int i = index; i < arr->length; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

int LinearSearch(struct Array arr, int n)
{
    for (int i = 0; i < arr.length; i++)
    {
        if (n == arr.A[i])
        {
            return i;
        }
    }
    return -1;
}

int LinearSearchUsingTransposition(struct Array* arr, int n)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (n == arr->A[i])
        {
            Swap(&arr->A[i], &arr->A[i - 1]);
            return i;
        }
    }
    return -1;
}

int LinearSearchUsingMoveToFront(struct Array* arr, int n)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (n == arr->A[i])
        {
            Swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int n)
{
    int l, mid, h;
    l = 0;
    h = arr.length - 1;
    
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (n == arr.A[mid])
            return mid;
        else if (n < arr.A[mid])
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int RecursiveBinarySearch(struct Array arr, int l,int h, int n)
{   
    int mid;

    if (l <= h)
    {
        mid = (l + h) / 2;
        if (n == arr.A[mid])
            return mid;
        else if (n < arr.A[mid])
        {
            return RecursiveBinarySearch(arr, l, mid - 1, n);
        }
        else
        {
            return RecursiveBinarySearch(arr, mid + 1, h, n);
        }
    }
    return -1;
}

int main() {
    struct Array arr = { {2,3,4,5,6},20,5 };
    Display(arr);
    printf("\n");
    //Append(&arr,7);
    //Insert(&arr, 2, 7);
    //printf("%d\n",Delete(&arr, 4));
    //printf("%d\n", LinearSearch(arr, 11));
    //printf("%d\n", LinearSearchUsingTransposition(&arr, 6));
    //printf("%d\n", LinearSearchUsingMoveToFront(&arr, 6));
    //printf("%d\n", BinarySearch(arr, 1));
    printf("%d\n", RecursiveBinarySearch(arr, 0, arr.length - 1, 7));
    printf("\n");
    Display(arr);
    return 0;
}