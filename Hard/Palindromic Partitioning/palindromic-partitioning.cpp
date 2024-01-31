//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
  inline bool isP(int i,int j, string &s){
      while(i<j){
          if(s[i]!=s[j]) return false;
          i++;j--;
      }
      return true;
  }
    int palindromicPartition(string str)
    {
       int n=str.size();
       int dp[n][n];
       for(int i=0;i<n;i++) dp[i][i]=0;
       
       for(int gap=1;gap<=n;gap++){
           for(int i=0;i<n-gap;i++){
               if(isP(i,i+gap,str)) dp[i][i+gap]=0;
               else{
                    dp[i][i+gap]=INT_MAX;
                   for(int k=i;k<i+gap;k++){
                       dp[i][(i+gap)]=min(dp[i][(i+gap)],1+dp[i][k]+dp[k+1][i+gap]);
                   }
               }
           }
       }
       return dp[0][n-1];
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends