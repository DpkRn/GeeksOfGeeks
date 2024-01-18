//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    void f(int i,vector<int> &p,vector<vector<int>> &ans,bool vis[],vector<int> &arr,int n){
        if(i==n){
            ans.push_back(p);
            return;
        }
        for(int j=0;j<n;j++){
            if(vis[j]==false){
            if(j>0){
                if(arr[j]==arr[j-1]&&vis[j-1]==false) continue;
                 p.push_back(arr[j]);
                 vis[j]=1;
                 f(i+1,p,ans,vis,arr,n);
                 p.pop_back();
                 vis[j]=0;
                }else{
                p.push_back(arr[j]);
                vis[j]=1;
                f(i+1,p,ans,vis,arr,n);
                p.pop_back();
                vis[j]=0;
               }
            }
        }
    }
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        vector<vector<int>> ans;
        bool vis[n];
        vector<int> p;
        sort(arr.begin(),arr.end());
        f(0,p,ans,vis,arr,n);
        return ans;
    }
};
/*
//using predefined method
class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        ans.push_back(arr);
        while(next_permutation(arr.begin(),arr.end())){
            ans.push_back(arr);
        }
        return ans;
    }
    
};
*/

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends