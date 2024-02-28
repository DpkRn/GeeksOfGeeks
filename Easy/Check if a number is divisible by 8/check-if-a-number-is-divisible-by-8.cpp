//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        int n=s.size();
        int num;
        if(n>3){
            string str(s.end()-4,s.end());
            num=stoi(str);
        }else{
             num=stoi(s);
        }
        if(num%8==0) return 1;
        return -1;
        //code here
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends