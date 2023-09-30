//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string solve(string a);

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        cout << solve(a) << endl;
    }
}

// } Driver Code Ends


string solve(string a) {
    // code here
    unordered_map<char,int> mp;
    
    for(auto ch:a){
        if(ch!='a' && ch!='e' && ch!='i' && ch!='o' && ch!='u'){
            mp[ch]++;
        }
    }
    
    if(mp.size()%2!=0){
        return "HE!";
    }
    
    return "SHE!";
}