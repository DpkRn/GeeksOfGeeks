//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void bfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>> &vis,vector<pair<int,int>> &vec,int row0,int col0){
        int m=grid.size();
        int n=grid[0].size();
        vis[r][c]=1;
        vec.push_back({r-row0,c-col0});
        queue<pair<int,int>> q;
        q.push({r,c});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            int dx[4]={0,0,1,-1};
            int dy[4]={1,-1,0,0};
            for(int i=0;i<4;i++){
                int nrow=row+dx[i]; int ncol=col+dy[i];
                if(nrow>=0&&nrow<m&&ncol>=0&&ncol<n&&!vis[nrow][ncol]&&grid[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    vec.push_back({nrow-row0,ncol-col0});
                    q.push({nrow,ncol});
                }
            }
            
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        set<vector<pair<int,int>>> st;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vector<pair<int,int>> vec;
                if(!vis[i][j]&&grid[i][j]==1){
                    bfs(i,j,grid,vis,vec,i,j);
                    st.insert(vec);
                    
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends