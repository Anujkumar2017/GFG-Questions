//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    string oddEven(string S) {
        // code here
        map<char,int> mp;
        for(char ch:S){
            mp[ch]++;
        }
        int ans=0;
        
        for(auto x:mp){
            if((x.first-'a'+1)%2==0 && x.second%2==0){
                ans++;
            }else if((x.first-'a'+1)%2!=0 && x.second%2!=0){
                ans++;
            }
        }
        // cout<<ans<<"\n";
        return (ans%2==0)? "EVEN":"ODD";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.oddEven(S) << endl;
    }
    return 0;
}

// } Driver Code Ends