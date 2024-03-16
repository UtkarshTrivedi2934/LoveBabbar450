//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
// 0     3         7
// 4 2 3 5 9 10 11 6
    void quickSort(int arr[], int low, int high)
    {
        if(low < high) {
            int p = partition(arr,low,high);
            quickSort(arr,low,p-1);
            quickSort(arr,p+1,high);
        }
    }
    
    public:
    int partition (int arr[], int s, int e)
    {
       int pivot = arr[s];
       int count = 0;
       for(int i = s+1;i<=e;i++) {
           if(arr[i] <= pivot) {
               count++;
           }
       }
       int pivotIndex = s+count;
       // reason behind swapping arr[s] instead of pivot, is to avoid data corruption
       // considering the case when pivot was swapped with arr[s+count], arr[s] would have remained at its place and 
       // arr[s+count] would have swapped with pivot i.e. a variable instead of an array element thus leading to data inconsistency
       swap(arr[s],arr[s+count]);
       
       int i = s;
       int j = e;
       
       while(i<pivotIndex and j > pivotIndex) {
           while(arr[i]<=pivot)
           i++;
           
           while(arr[j]>pivot)
           j--;
           
           if(i<pivotIndex and j > pivotIndex) {
               swap(arr[i++],arr[j--]);
           }
           
       }
       return pivotIndex;
    }
};

// 5 10 3 6 9 2 11 4

//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends