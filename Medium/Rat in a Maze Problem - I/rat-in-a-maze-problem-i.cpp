//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    void solve(int r,int c,int n,string &str,vector<string> &ans,vector<vector<int>> &m){
        if(r==n-1&&c==n-1){
            ans.push_back(str);
            return;
        }
        if(r<0||c<0||r==n||c==n||m[r][c]==0) return;
        m[r][c]=0;
        //going down
        str.push_back('D');
        solve(r+1,c,n,str,ans,m);
        str.pop_back();
         //going left
        str.push_back('L');
        solve(r,c-1,n,str,ans,m);
        str.pop_back();
        //going right
        str.push_back('R');
        solve(r,c+1,n,str,ans,m);
        str.pop_back();
        //going up
        str.push_back('U');
        solve(r-1,c,n,str,ans,m);
        str.pop_back();
        
        m[r][c]=1;
        
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(m[0][0]==0||m[n-1][n-1]==0) return {"-1"};
        vector<string> ans;
        string str;
        solve(0,0,n,str,ans,m);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends