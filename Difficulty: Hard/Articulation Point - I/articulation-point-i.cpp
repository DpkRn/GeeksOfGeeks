//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
        
        vector<int> tin;
        vector<int> low;
        vector<int> vis;
        vector<int> mark;
        int timer=1;
    void dfs(int node,int par,vector<int> adj[]){
        vis[node]=1;
        tin[node]=timer;
        low[node]=timer;
        timer++;
        int child=0;
        for(auto it:adj[node]){
            if(par==it) continue;
            if(!vis[it]){
                dfs(it,node,adj);
                 low[node]=min(low[it],low[node]);
                if(low[it]>=tin[node]&&par!=-1) mark[node]=1;;
               child++;
                
            }else{
                low[node]=min(tin[it],low[node]);
            }
        }
        if(child>1&&par==-1) mark[node]=1;
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        int n=V;
        tin=vector<int>(n,0);
        low=vector<int>(n,0);
        vis=vector<int>(n,0);
        mark= vector<int> (n,0);
        vector<int> ans;
        dfs(0,-1,adj);
        for(int i=0;i<n;i++){
            if(mark[i]==1) ans.push_back(i);
        }
        if(ans.size()==0) return {-1};
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends