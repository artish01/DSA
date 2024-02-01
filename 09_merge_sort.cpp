#include  <iostream>
using  namespace std;



void merge(int A[],int temp[],int left,int mid,int right)
{
    
    int left_end = mid-1;
    int temp_pos  = left;
    int size = right-left+1;

    while((left<=left_end) && (mid<=right))
    {
        if(A[left]<=A[mid])
        {
            temp[temp_pos] = A[left];
            temp_pos++;
            left++;

        }
        else{
        	temp[temp_pos] = A[mid];
            temp_pos++;
            mid++;
        }

    }
    while(left<=left_end)
    {
        temp[temp_pos] = A[left];
        temp_pos =temp_pos+ 1;
        left++;

    }

	while(mid<=right)
    {
        temp[temp_pos] = A[mid];
        temp_pos+=1;
        mid+=1;
    }


	for(int i=0; i<size; i++)
	{
		A[right] = temp[right];
        
		right--;
		
	}


}

void mergesort(int A[],int temp[],int left,int right)
{
	int mid;
	if(right>left)
	{
		mid = (left+right)/2; // 0
		mergesort(A,temp,left,mid);
		mergesort(A,temp,mid+1,right);
		merge(A,temp,left,mid+1,right);
	}
	
}

int main()
{


	int A[] = {5,32,12,23,13,1,44,2,2,1,3,34,44};
	int n = 13;
	int left = 0;
	int right = n-1;
	int temp[n];

	mergesort(A,temp,left,right);

	for(int i=0; i<n; i++)
	{
		cout<<A[i]<<" ";
	}




	return 0;


}