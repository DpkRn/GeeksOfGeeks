//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        // Code here
        vector<pair<int,int>> adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>cost(n,1e9);
        cost[src]=0;
        queue<pair<int,pair<int,int>>> pq;
        //priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{src,0}});
        while(!pq.empty()){
            int stop=pq.front().first;
            int node=pq.front().second.first;
            int dist=pq.front().second.second;
            pq.pop();
            //if(node==dst) return 
           if(stop>k) continue;
           //cout<<stop<<endl;
            for(auto it:adj[node]){
                int adjNode=it.first;
                int adjCost=it.second;
                
                if(dist+adjCost<cost[adjNode]&&stop<=k){
                        cost[adjNode]=dist+adjCost;
                        pq.push({stop+1,{adjNode,dist+adjCost}});
                }
            }   
            
            
        }
        // for(auto it:cost){
        //     cout<<it<<" ";
        // }
        return cost[dst]==1e9?-1:cost[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends