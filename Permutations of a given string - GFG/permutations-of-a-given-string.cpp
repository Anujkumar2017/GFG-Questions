//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void permutation(string s, int idx, vector<string>& ans){
	        if(idx==s.size()-1){
	            ans.push_back(s);
	            return;
	        }
	        
	        for(int i=idx;i<s.size();i++){
	            swap(s[idx],s[i]);
	            //cout<<idx<<" "<<i<<"\n";
	            permutation(s,idx+1,ans);
	            
	        }
	    }
	    
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> ans;
		    permutation(S,0,ans);
		    
		    sort(ans.begin(),ans.end());
		    auto itr =unique(ans.begin(),ans.end());
		    ans.erase(itr,ans.end());
		    
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends