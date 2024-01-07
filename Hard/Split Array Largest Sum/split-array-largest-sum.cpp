//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int isValid(int arr[],int N,int mid,int k){
        int sum=0;
        int cnt=1;
        for(int i=0;i<N;i++){
            if(sum+arr[i]>mid){
               cnt++;
               sum=arr[i];
            }
            else{
               sum=sum+arr[i];
            }
            if(cnt>k) return false;
            
        }
       
        //cout<<cnt<<" ";
        
        /*
        //this will not work because it ignore the last array if its not got  sum >=mid
        for(int i=0;i<N;i++){
            if(sum+arr[i]<=mid){
                sum=sum+arr[i];
            }
            else{
                sum=arr[i];
                cnt++;
            }
            
        }
        cnt+=sum/mid;
        cout<<cnt<<" ";
        */
        return cnt<=k;
    }
    int splitArray(int arr[] ,int N, int K) {
        // code here
       int low=INT_MIN;
       int sum=0;
       for(int i=0;i<N;i++){
           low=max(arr[i],low);
           sum+=arr[i];
       }
       //sort(arr,arr+N);
       
       
       int high=sum;
       while(low<=high){
           int mid=(low+high)>>1;
          // cout<<mid<<" ";
           if(isValid(arr,N,mid,K))
               high=mid-1;
            else
               low=mid+1;
       }
       return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends