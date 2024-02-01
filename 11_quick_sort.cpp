#include <bits/stdc++.h>
using namespace std;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partation(int arr[], int start, int end)
{
    int pivot = arr[start];
    int left = start;
    int right = end;
     

    while(left<right)
    {
        while(arr[left]<=pivot && left<=end-1)
        {
            left++;
        }
        while(arr[right]>pivot && right>=start+1)
        {
            right--;
        }
        if(left<right)
        {
            swap(arr[left],arr[right]);

        }
        
        

    }
    swap(arr[start],arr[right]);
    return right;
}

void quicksort(int arr[], int st, int end)
{

    if (st < end)
    {
        int pi = partation(arr, st, end);

        quicksort(arr, st, pi - 1);
        quicksort(arr, pi + 1, end);
     
       
    }
}

void print(int arr[], int n)
{
    cout << "Sorted array ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{

    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int st = 0;
    int end = n - 1;
    quicksort(arr, st, end);

    print(arr,n);

    return 0;
}

// int i = (st - 1);

    // for (int j = st; j <= end; j++)
    // {
    //     if (arr[j] < pivot)
    //     {
    //         i++; // bcz i is low and it is -1 initially
    //         swap(&arr[i], &arr[j]);
    //     }
    // }
    // // swap(&arr[i + 1], &arr[end]);
    // swap(arr[i+1],arr[end]);

    // return (i + 1);