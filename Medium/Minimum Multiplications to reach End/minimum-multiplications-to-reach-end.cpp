//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int src, int end) {
        queue<pair<int,int>> q;
        
        q.push({0,src});
        int mod=100000;
        vector<int> dist(100000,1e5);
        dist[src]=0;
        while(!q.empty()){
            int steps=q.front().first;
            int value=q.front().second;
             if(value==end) return steps;
            q.pop();
            for(auto it:arr){
                int curr=(value*it)%mod;
               
                if(steps+1<dist[curr]){
                    dist[curr]=steps+1;
                     q.push({steps+1,curr});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends