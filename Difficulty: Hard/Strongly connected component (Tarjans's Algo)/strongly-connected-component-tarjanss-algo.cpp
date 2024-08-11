//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    	void dfs(int src,vector<int> adj[],stack<int> &st,int vis[]){
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
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        //code here
         int vis[V]={0};
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i])
             dfs(i,adj,st,vis);
        }
       
        
        vector<int> revG[V];
        for(int i=0;i<V;i++){
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
                sort(temp.begin(),temp.end());
                scc.push_back(temp);
            }
        }
        sort(scc.begin(),scc.end());
        
        
        return scc;
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

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}


// } Driver Code Ends