//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
    
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
               int v=it.first;
               int wt=it.second;
               if(dist[node]+wt<dist[v]) 
               {dist[v]=dist[node]+wt;
                q.push(it.first);
               }
            }
        }
        
        for(int i=0;i<dist.size();i++){
            if(dist[i]==INT_MAX) dist[i]=-1;
        }
        return dist;
    }
};
/*
  // code here
  //without topo
        
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