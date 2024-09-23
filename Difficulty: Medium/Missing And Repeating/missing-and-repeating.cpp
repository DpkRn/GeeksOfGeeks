//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

#define ll long long
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        ll n=arr.size();
        ll sum=(n*(n+1))/2, sq=(n*(n+1)*(2*n+1))/6;
        ll csum=0, csq=0;
        for(ll i:arr){
            csum+=i;
            csq+=i*i;
        }
        ll eq1=sq-csq,eq2=sum-csum;
        ll eq3=eq1/eq2;
        ll a=(eq2+eq3)/2;
        ll b=eq3-a;
        return {b,a};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends