#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int Get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        return arr.A[index];
    }
    return -1;
}

void Set(struct Array *arr, int index, int n)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = n;
    }  
}

int Max(struct Array arr)
{
    int max = arr.A[0];

    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}

int Min(struct Array arr)
{
    int min = arr.A[0];

    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

int Sum(struct Array arr)
{
    int sum = 0;

    for (int i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }   
    return sum;
}

int RecursiveSum(struct Array arr, int n)
{
    if (n < 0)
        return 0;
    else
    {
        return RecursiveSum(arr, n - 1) + arr.A[n];
    }
}

int Avg(struct Array arr)
{
    return Sum(arr) / arr.length;
}

void Reverse(struct Array* arr)
{
    int* B;
    int i, j;

    B = (int*)malloc(arr->length * sizeof(int));
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
        B[j] = arr->A[i];
    for (i = 0; i < arr->length; i++)
        arr->A[i] = B[i];

}

void ReverseUsingSwap(struct Array* arr)
{
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        Swap(&arr->A[i], &arr->A[j]);
    }
}

void LeftShift(struct Array* arr)
{
    int i;
    for (i = 0; i < arr->length-1; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->A[arr->length - 1] = 0;
}

void LeftRotation(struct Array* arr)
{
    int i, rotationVar;
    
    rotationVar = arr->A[0];

    for (i = 0; i < arr->length - 1; i++)
    {
        
        arr->A[i] = arr->A[i + 1];
    }

    arr->A[arr->length - 1] = rotationVar;
}

void RightShift(struct Array* arr)
{
    int i;
    for (i = arr->length-1; i > 0; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[0] = 0;
}

void RightRotation(struct Array* arr)
{
    int i, rotationVar;

    rotationVar = arr->A[arr->length-1];

    for (i = arr->length - 1; i > 0; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[0] = rotationVar;

}

void InsertInSortedArray(struct Array* arr, int n)
{
    int i = arr->length - 1;

    if (arr->length == arr->size)
        return;

    while (arr->A[i] > n)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = n;
    arr->length++;

}

bool IsSorted(struct Array arr)
{
    int i;   

    for (i = 0; i < arr.length-1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
            return false;
    }
    return true;
}

void MoveNegativesOnLeftSide(struct Array* arr)
{
    int i, j;
    i = 0;
    j = arr->length - 1;

    while (i < j)
    {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[j] >= 0)
            j--;

        if (i < j)
        {
            Swap(&arr->A[i], &arr->A[j]);
        }
    } 
}

struct Array* Merge(struct Array* arr1, struct Array* arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct Array* arr3 = (struct Array*)malloc(sizeof(struct
        Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return arr3;
}

int main() {
    struct Array arr = { {2,3,4,5,6},10,5 };
    //struct Array arr = { {2,-3,25,10,-15,-7},10,5 };
    struct Array arr1 = { {2,6,10,15,25},10,5 };
    struct Array arr2 = { {3,4,7,18,20},10,5 };
    struct Array* arr3;

    Display(arr);
    printf("\n");
    //Append(&arr,7);
    //Insert(&arr, 2, 7);
    //printf("%d\n",Delete(&arr, 4));
    //printf("%d\n", LinearSearch(arr, 11));
    //printf("%d\n", LinearSearchUsingTransposition(&arr, 6));
    //printf("%d\n", LinearSearchUsingMoveToFront(&arr, 6));
    //printf("%d\n", BinarySearch(arr, 1));
    //printf("%d\n", RecursiveBinarySearch(arr, 0, arr.length - 1, 7));
    //printf("%d\n", Get(arr, 2));
    //Set(&arr, 2, 7);
    //printf("%d\n", Max(arr));
    //printf("%d\n", Min(arr));
    //printf("%d\n", Sum(arr));
    //printf("%d\n", RecursiveSum(arr,4));
    //printf("%d\n", Avg(arr));
    //Reverse(&arr);
    //ReverseUsingSwap(&arr);
    //LeftShift(&arr);
    //LeftRotation(&arr);
    //RightShift(&arr);
    //RightRotation(&arr);
    //InsertInSortedArray(&arr,3);
    //printf("%d\n", IsSorted(arr));
    //MoveNegativesOnLeftSide(&arr);
    arr3 = Merge(&arr1, &arr2);
    Display(*arr3);
    printf("\n");
    //Display(arr);
    return 0;
}