//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        // your code here
        map<char,int> mp;
        int n=s.size();
        int i,ans=0,j=0;
        for(i=0;i<n;i++){
            mp[s[i]]++;
            if(mp.size()>k){
                ans=max(ans,i-j);
                while(mp.size()!=k){
                    mp[s[j]]--;
                    if(mp[s[j]]==0){
                        mp.erase(s[j]);
                    }
                    j++;
                }
            }
            // cout<<i<<" "<<j<<"\n";
        }
        
        // cout<<<<"\n";
        ans=max(ans,i-j);
        if(mp.size()!=k)
            return -1;
        return ans;
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends