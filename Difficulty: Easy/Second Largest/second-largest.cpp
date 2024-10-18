//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
  
    int getSecondLargest(vector<int> &arr) {
       int first=accumulate(arr.begin(),arr.end(),-1,[&](int a,int b){return max(a,b);});
       int second=accumulate(arr.begin(),arr.end(),-1,[&](int a,int b){
           if(b==first) return a;
           return max(a,b);
           
       });
       return second;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends