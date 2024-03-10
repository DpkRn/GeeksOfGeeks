//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int src,vector<vector<int>> &adj,stack<int> &st,int vis[]){
	    vis[src]=1;
	    for(auto it:adj[src]){
	        if(!vis[it]){
	            dfs(it,adj,st,vis);
	        }
	    }
	    st.push(src);
	}
	void dfs1(int src,vector<int> adj[],vector<int> &temp,int vis[]){
	    vis[src]=1;
	    for(auto it:adj[src]){
	        if(!vis[it]){
	            dfs1(it,adj,temp,vis);
	        }
	    }
	    temp.push_back(src);
	    
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        int vis[V]={0};
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i])
             dfs(i,adj,st,vis);
        }
       
        
        vector<int> revG[V];
        for(int i=0;i<adj.size();i++){
            vis[i]=0;
            for(auto it:adj[i]){
                revG[it].push_back(i);
            }
        }
        
        int cnt=0;
       
        vector<vector<int>> scc;
        while(!st.empty()){
            vector<int> temp;
            int node=st.top();
           // cout<<node<<" "<<endl;
            st.pop();
            if(!vis[node]){
                cnt++;
                dfs1(node,revG,temp,vis);
                scc.push_back(temp);
            }
        }
        // for(auto itvec:scc){
        //     for(auto it:itvec){
        //         cout<<it<<" ";
        //     }
        //     cout<<endl;
        // }
        return cnt;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends