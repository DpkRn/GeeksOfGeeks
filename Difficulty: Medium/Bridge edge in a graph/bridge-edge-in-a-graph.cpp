//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{   int timer;
    vector<int> vis;
    vector<int> low;
    vector<int> tin;
	public:
    //Function to find if the given edge is a bridge in graph.
    bool dfs(int node,int par,vector<int> adj[],int c,int d){
        vis[node]=1;
        low[node]=timer;
        tin[node]=timer;
        timer++;
        for(auto it:adj[node]){
            if(it==par) continue;
            if(!vis[it]){
                if(dfs(it,node,adj,c,d)) return true;;
                low[node]=min(low[it],low[node]);
                if(low[it]>tin[node]){
                    if(node==c&&it==d||node==d&&it==c) return true;
                }
            }else{
                low[node]=min(tin[it],low[node]);
            }
        }
        return false;
        
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        int n=V;
       
        vis=vector<int>(n,0);
        low=vector<int>(n,0);
        tin=vector<int>(n,0);
        for(int i=0;i<V;i++){
            timer=0;
            if(!vis[i])
        if(dfs(i,-1,adj,c,d)) return true;
        }
        return false;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends