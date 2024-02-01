#include <iostream>
using namespace std;

void ins(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j;

        int current = arr[i];

        for (j = i - 1; j >= 0; j--)
        {
            if (current < arr[j])
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = current;

        
    }
}

// 1 2 2 5 4
// 
// void ins(int arr[],int n)
// {
//     for(int i=1; i<n; i++)
//     {
//         int current = arr[i];
//         int j;

//         for(int i=i-1; i>=0; i++)
//         {
//             if(current<arr[j])
//             {
//                 arr[j+1] = arr[j];
//             }
//             else
//             {
//                 break;
//             }
//         }
//         arr[j+1] = current;
//     }
// }

int main()
{

   int arr[] = {3,1,4,5,9,2,6,5};
    int n = sizeof(arr) / sizeof(arr[0]);

    ins(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}