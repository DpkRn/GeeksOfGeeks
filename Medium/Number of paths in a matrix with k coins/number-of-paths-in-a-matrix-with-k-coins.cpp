//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int f(int i,int j,int k,vector<vector<int>> &arr,vector<vector<vector<int>>> &dp){
        if(i==0&&j==0){
            if(k==arr[i][j]) return 1;
            return 0;
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int left=0,up=0;
        
        if(j-1>=0&&k-arr[i][j]>=0) left=f(i,j-1,k-arr[i][j],arr,dp);
        if(i-1>=0&&k-arr[i][j]>=0) up=f(i-1,j,k-arr[i][j],arr,dp);
        
        return dp[i][j][k]=left+up;
        
    }
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
        return f(n-1,n-1,k,arr,dp);
        // Code Here
    //     vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(k+1,0)));
    //     dp[0][0][0]=1;
       
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=n;j++){
    //             for(int sum=1;sum<=k;sum++){
    //              if(sum-arr[i-1][j-1]>=0) dp[i][j][sum]+=dp[i-1][j][sum-arr[i-1][j-1]];
    //              if(sum-arr[i-1][j-1]>=0) dp[i][j][sum]+=dp[i][j-1][sum-arr[i-1][j-1]];
    //             }
                
    //         }
            
    //     }
    //     return dp[n][n][k];
     }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends