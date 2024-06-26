//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
       int n=arr.size();
       int dp[n+1][sum+1];
       memset(dp,0,sizeof(dp));
       dp[0][0]=1;
       for(int i=1;i<=n;i++){
           for(int j=0;j<=sum;j++){
               int notpick=dp[i-1][j]; //not pick case
               int pick=false;
               if(j-arr[i-1]>=0) pick=dp[i-1][j-arr[i-1]]; //pick case
               dp[i][j]=pick||notpick;
           }
       }
       
       return dp[n][sum];
    }
};



//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends