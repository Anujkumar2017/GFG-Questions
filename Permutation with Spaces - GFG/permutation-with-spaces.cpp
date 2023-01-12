//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    vector<string> ans;
    
    void solve(string a, string b){
        if(b.size()==0){
            ans.push_back(a);
            return;
        }
        solve(a+" "+b[0],b.substr(1));
        solve(a+b[0],b.substr(1));
    }
    
    vector<string> permutation(string S){
        // Code Here
        string a=S.substr(0,1);
        string b=S.substr(1);
        solve(a,b);
        return ans;
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends