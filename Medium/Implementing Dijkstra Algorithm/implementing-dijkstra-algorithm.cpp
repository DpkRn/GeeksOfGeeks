//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        queue<int> q;
        vector<int> dist(V,1e9);
        q.push(S);
        dist[S]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it1:adj[node]){
               // for(auto it1:it){
                int v=it1[0];
                int wt=it1[1];
                if(dist[node]+wt<dist[v]){
                    dist[v]=dist[node]+wt;
                    q.push(v);
                }
                //}
            }
        }
        
        for(auto &it:dist){
            if(it==1e9) it=-1;
        }
        return dist;
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends