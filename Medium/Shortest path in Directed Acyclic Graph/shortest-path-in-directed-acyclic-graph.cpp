//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  void dfs(int node,vector<pair<int,int>> adj[],int vis[],stack<int> &st){
      vis[node]=1;
      for(auto it:adj[node]){
          if(!vis[it.first]){
              dfs(it.first,adj,vis,st);
          }
      }
      st.push(node);
  }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
      vector<pair<int,int>> adj[N];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        int vis[N]={0};
        stack<int> st;
        for(int i=0;i<N;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        vector<int> dist(N,1e5);
        dist[0]=0;
         while(!st.empty()){
            int node=st.top();
            st.pop();
            for(auto it:adj[node]){
               int v=it.first;
               int wt=it.second;
               if(dist[node]+wt<dist[v]) dist[v]=dist[node]+wt;
            }
        }
        for(int i=0;i<dist.size();i++){
            if(dist[i]==1e5) dist[i]=-1;
        }
        return dist;
    }
};
/*
  // code here
        vector<pair<int,int>> adj[N];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(N,INT_MAX);
        dist[0]=0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                dist[it.first]=min(dist[it.first],dist[node]+it.second);
                q.push(it.first);
            }
        }
        
        for(int i=0;i<dist.size();i++){
            if(dist[i]==INT_MAX) dist[i]=-1;
        }
        return dist;
*/

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends