//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
   
public:
 map<int,int> primeFactors(int n) 
    { 
    map<int,int> mp;
    // Print the number of 2s that divide n 
    while (n % 2 == 0) 
    { 
        mp[2]++;
        n = n/2; 
    } 
 
    // n must be odd at this point. So we can skip 
    // one element (Note i = i +2) 
    for (int i = 3; i <= sqrt(n); i = i + 2) 
    { 
        // While i divides n, print i and divide n 
        while (n % i == 0) 
        { 
           mp[i]++; 
            n = n/i; 
        } 
    } 
 
    // This condition is to handle the case when n 
    // is a prime number greater than 2 
    if(n>2)
    mp[n]++;
    return mp;
} 
	int sumOfPowers(int a, int b){
	    int cnt=0;
	   for(int i=a;i<=b;i++){
	       map<int,int> mp=primeFactors(i);
	       for(auto x:mp){
	           cnt=cnt+x.second;
	       }
	   }
	   return cnt;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends