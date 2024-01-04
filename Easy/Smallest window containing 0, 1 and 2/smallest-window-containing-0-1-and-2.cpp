//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#include<bits/stdc++.h>
class Solution {
  public:
  bool check(int arr[]){
      if(arr[0]>0&&arr[1]>0&&arr[2]>0)
      return true;
      return false;
  }
    int smallestSubstring(string S) {
        // Code here
        int arr[3]={0,0,0};
        int ans=S.size()+1;
        int l=0;int r=0;
        while(r<S.size()){
            arr[S[r]-'0']++;
            if(check(arr)){
                while(l<=r&&check(arr)){
                    ans=min(ans,r-l+1);
                    arr[S[l]-'0']--;
                    l++;
                }
            }
        r++;
        }
        if(ans==S.size()+1)
        return -1;
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends