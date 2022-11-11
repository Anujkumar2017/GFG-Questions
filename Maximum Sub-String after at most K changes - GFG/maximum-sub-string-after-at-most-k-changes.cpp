//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
		    // Code here
		    // varible size sliding window
		    int i=0,j=0;
		    int ans=INT_MIN,mx=0;
		    map<char,int> mp;
		    
		    for(j=0;j<s.size();j++){
		        mp[s[j]]++;
		        mx=max(mx,mp[s[j]]);
		        // if size between (i and j) - mx i.e. number of changes to be made is greter than k 
		        if(j-i+1-mx>k){
		            mp[s[i]]--;
		            i++;
		        }
		        // maximum sub string 
		        ans=max(ans,j-i+1);
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends