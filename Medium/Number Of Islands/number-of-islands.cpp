//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class disjointSet{
    public:
    vector<int> size;
    vector<int> parent;
    
    disjointSet(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    
    int findUPar(int node){
        if(parent[node]==node) return node;
        return parent[node]=findUPar(parent[node]);
    }
    void unionBySize(int u,int v){
        int epu=findUPar(u);
        int epv=findUPar(v);
        if(epu==epv) return;
        if(size[epu]<size[epv]){
            parent[epu]=epv;
            size[epv]+=size[epu];
        }else{
             parent[epv]=epu;
            size[epu]+=size[epv];
        }
    }
   
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<int> ans;
        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        disjointSet dsu(m*n);
        // (r,c) num=r*m+c;
        

        vector<vector<int>> mat(n,vector<int>(m,0));
        int cnt=0;
        for(auto it:operators){
            int r=it[0]; int c=it[1];
            if(mat[r][c]==0){
                cnt++;
                mat[r][c]=1;
                for(int i=0;i<4;i++){
                    int newx=r+dx[i],newy=c+dy[i];
                    if(newx>=0&&newx<n&&newy>=0&&newy<m){
                        int curr=r*m+c;
                            int adj=newx*m+newy;
                        if(mat[newx][newy]==1&&dsu.findUPar(curr)!=dsu.findUPar(adj)){
                            
                            dsu.unionBySize(curr,adj);
                            cnt--;
                        }
                    }
                }
                ans.push_back(cnt);
            }
            else{
                ans.push_back(cnt);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends