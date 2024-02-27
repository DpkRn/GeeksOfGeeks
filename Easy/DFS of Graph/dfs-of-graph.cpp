//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void helper(vector<int> adj[],int node,vector<int> &dfs,vector<bool>& vis){
        if(adj[node].empty()) return ;
       // dfs.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
               vis[it]=true;
               dfs.push_back(it);
               helper(adj,it,dfs,vis);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
       vector<int> dfs;
       vector<bool> vis(V,0);
       dfs.push_back(0);
       vis[0]=true;
       helper(adj,0,dfs,vis);
       return dfs;
    }
};

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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends