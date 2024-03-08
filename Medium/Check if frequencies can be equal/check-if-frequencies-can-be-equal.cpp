//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    map<char,int> mp;
	    for(auto c:s){
	        mp[c]++;
	    }
	    int cnt=0;
	    int cntchar=0;
	    int mini=INT_MAX;
	    int maxi=INT_MIN;
	    for(auto it:mp){
	        cntchar++;
	        mini=min(mini,it.second);
	        maxi=max(maxi,it.second);
	    }
	    map<int,int> freq;
	    for(auto it:mp){
	        freq[it.second]++;
	        
	    }
	    
	    
	    if(freq.size()==1) return 1;
	    if(freq.size()>2) return 0;
	   
	    for(auto num:freq){
	       if(num.second==1&&num.first==1) return 1;
	    }
	    //if(s.size()-maxi*(cntchar-1)<=1) return 1;
	    if(s.size()-mini*cntchar<=1) return 1;
	    return 0;
	   // if
	    
	    
	    
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends