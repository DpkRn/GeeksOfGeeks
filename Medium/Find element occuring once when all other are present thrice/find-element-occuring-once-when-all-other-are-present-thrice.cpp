//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        // code here
        int ele=0;
        for(int bits=0;bits<32;bits++){
            int cnt=0;
            for(int i=0;i<N;i++){
                if((arr[i]>>bits)&1==1) cnt++;
            }
            if(cnt%3==1)
             ele+=(1<<bits);
        }
        return ele;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends