//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int src,vector<int> adj[],vector<int>&color,int prevC){
        color[src]=(!prevC);
        for(auto adjNode:adj[src]){
            if(color[adjNode]==-1){
                if(!dfs(adjNode,adj,color,color[src])) return false;
            }else{
                if(color[adjNode]==color[src]) return false;
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	   vector<int> color(V,-1);
	   for(int i=0;i<V;i++){
	       if(color[i]==-1)
	       if(!dfs(i,adj,color,1)) return false;
	   }
	   return true;
	}

};
//using BFS
/*
bool bfs(int src,vector<int> adj[],vector<int>&color){
        queue<int> q;
        q.push(src);
        color[src]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(color[it]==-1){
                    q.push(it);
                    color[it]=!color[node];
                }else{
                    if(color[it]==color[node]) return false;
                }
                
            }
        }
        return true;
    }
    
	bool isBipartite(int V, vector<int>adj[]){
	   vector<int> color(V,-1);
	   for(int i=0;i<V;i++){
	       if(color[i]==-1)
	       if(!bfs(i,adj,color)) return false;
	   }
	   return true;
       
	}*/

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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends