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
    void merge(int arr[], int l, int m, int r)
    {
     int l1=l; int r1=m; int l2=m+1; int r2=r; 
     vector<int> temp(r-l+1);
     int i=0;
     while(l1<=r1&&l2<=r2){
         if(arr[l1]<arr[l2]){
            temp[i++]=arr[l1++]; 
         }else temp[i++]=arr[l2++];
     }
     while(l1<=r1){
         temp[i++]=arr[l1++];
     }
     
     while(l2<=r2){
         temp[i++]=arr[l2++];
     }
     
     for(int i=l; i<=r;i++){
         arr[i]=temp[i-l];
     }
     
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l==r) return;
        int m=(l+r)>>1;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends