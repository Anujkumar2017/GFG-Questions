//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
	string printMinIndexChar(string S, string patt)
	{
	    // Code here
	    map<char,int> mp;
	    int n=S.size(),m=patt.size();
	  
	    for(int i=0;i<n;i++){
	        if(mp.find(S[i])==mp.end())
	            mp[S[i]]=i;
	    }
	    int mn=INT_MAX;
	    for(int i=0;i<m;i++){
	        if(mp.find(patt[i])!=mp.end()){
	            mn=min(mn,mp[patt[i]]);
	            //cout<<mn<<" ";
	        }
	    }
	    
	    if(mn!=INT_MAX){
	        string ans;
	        ans=S[mn];
	        return ans;
	    }else
	        return "$";
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        string str;
        cin>>str;
        string patt;
        cin >> patt;
        Solution obj;
        cout<<obj.printMinIndexChar(str, patt)<<endl;
    }
    
	return 0;
}
// } Driver Code Ends