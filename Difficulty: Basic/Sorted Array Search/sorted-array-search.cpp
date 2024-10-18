//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int f(int arr[],int l, int r,int k){
      if(l>r) return -1;
      int m=(l+r)/2;
      if(arr[m]==k){
          return 1;
      }
      if(arr[m]<k){
          return f(arr,m+1,r,k);
      }
          return f(arr,l,m-1,k);
  }
    int searchInSorted(int arr[], int N, int K) {

        return f(arr,0,N-1,K);
    }
};

//{ Driver Code Starts.

int main(void) {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int arr[n];

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.searchInSorted(arr, n, k) << endl;
    }

    return 0;
}

// } Driver Code Ends