//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool dfs(int node,vector<int>adj[],int vis[],int pathVis[],int check[]){
        vis[node]=1;
        pathVis[node]=1;
        check[node]=0;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathVis,check)==true){
                    check[node]=0;
                    return true; 
                }
            }else{
                if(pathVis[it]){
                    check[node]=0;
                    return true; 
                }
            }
        }
        pathVis[node]=0;
        check[node]=1;
        return false;
    }
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {

        int vis[n]={0};
        int pathVis[n]={0};
        int check[n]={0};
        // for(int i=0;i<n;i++){
        //         vis[i]=0;
        //     pathVis[i]=0;
        //     check[i]=0;
        // }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                
                dfs(i,adj,vis,pathVis,check);
            }
        }
     vector<int> vec;
        for(int i=0;i<n;i++){
            if(check[i]){
                vec.push_back(i);
            }
        }
        return vec;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends