//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
       unordered_map<int,int> mp;
       mp[0]=-1;
       int maxi=0,sum=0;
       for(int i=0;i<N;i++){
           sum+=A[i];
           int search=sum-K;
           if(mp.find(search)!=mp.end()){
               maxi=max(maxi,i-mp[search]);
           }
           if(mp.find(sum)==mp.end()){
               mp[sum]=i;
           }
       }
       return maxi;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends