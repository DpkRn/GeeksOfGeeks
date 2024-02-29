//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	//1 001  1 001 2 010  2 010 
	//2 010  1 001 1 001  1 010
	const long long mod=1e9+7;
	long long sumBitDifferences(int arr[], int n) {
	    long long sum=0;
	    for(int i=0;i<17;i++){
	        int cnt1=0;int cnt0=0;
	        for(int j=0;j<n;j++){
	            if(arr[j]&(1<<i)) cnt1++;
	            else cnt0++;
	        }
	        long long res=1ll*cnt1*cnt0;
	        sum+=res*2;
	        
	    }
	    return sum;
	    
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumBitDifferences(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends