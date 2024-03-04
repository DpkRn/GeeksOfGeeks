//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  //USING  BFS
    
    bool isCyclic(int V, vector<int> adj[]) {
       //as we know topoSort only work on Directed Acyclic Graph so we will apply topoSort 
       //using kahn's Algorithm if fully performed successful then it will be acyclic else cyclic
       int indegree[V]={0};
       for(int i=0;i<V;i++){
           for(auto it:adj[i])
           indegree[it]++;
       }
       queue<int> q;
       for(int i=0;i<V;i++){
           if(indegree[i]==0) q.push(i);
       }
       int cnt=0;
       while(!q.empty()){
           int node=q.front();
           q.pop();
           cnt++;
           for(auto it:adj[node]){
               indegree[it]--;
               if(indegree[it]==0) q.push(it);
               
           }
           
       }
       if(V==cnt) return false;
       else return true;
       
    }
};
//using DFS
 /*
    bool dfs(int node,vector<int> adj[],vector<int> &vis,vector<int> &path){
        vis[node]=1;
        path[node]=1;
        for(auto adjNode:adj[node]){
            //node has not been visited then
            if(!vis[adjNode]){
                if(dfs(adjNode,adj,vis,path)) return true;
            }else 
            //node has already in path then
            if(path[adjNode]==1) return true;
        }
        path[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> path(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,path)) return true;
            }
            
        }
        return false;
    }
   */ 

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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends