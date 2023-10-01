//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int fun(string s);

int main() {
    int tt;
    string s;
    cin >> tt;
    while (tt--) {
        cin >> s;
        cout<<fun(s)<<endl;
        
    }
    return 0;
}
// } Driver Code Ends


int fun(string s)
{
    //code here
    int n=s.size();
    unordered_map<string,int> mp;
    
    for(int i=0; i<n-1; i++){
        mp[s.substr(i,2)]++;    
    }
    
    return mp.size();
    
}