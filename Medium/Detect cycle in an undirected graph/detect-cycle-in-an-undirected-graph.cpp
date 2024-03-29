//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    //using dfs
    bool detect(int src,int parent,vector<int> adj[],vector<bool> &vis){
       vis[src]=true;
       for(auto it:adj[src]){
         if(!vis[it]){
             if(detect(it,src,adj,vis)==true) return true;
         }else{
             if(parent!=it)
             return true;
         }
           
       }
       return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V,0);
        for(int i=0;i<V;i++){
           if(!vis[i])
           if(detect(i,-1,adj,vis)==true) return true; 
        }
        return false;
    }
};
/*
//using bfs
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detect(int src,vector<int> adj[],vector<int> &vis){
        
        queue<pair<int,int>> q;
        q.push({src,-1});
        vis[src]=1;
        
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    q.push({it,node});
                    vis[it]=1;
                }else{
                    if(parent!=it) return true;
                }
            }
        }
        return false;
        
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i])
            if(detect(i,adj,vis)==true) return true;
        }
         return false;
    }
   
};
*/

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends