//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(int &i,vector<int>& ans, int N, int &n,int a, int c, int b){
        if(N==0){
            return;
        }
        
        solve(i,ans,N-1,n,a,b,c);
        i++;
        // cout<<N<<" "<<a<<" "<<c<<"\n";
        // cout<<i<<" "<<n<<"\n";
        if(i==n){
            ans.push_back(a);
            ans.push_back(c);
        }
        solve(i,ans,N-1,n,b,c,a);
    }
    vector<int> shiftPile(int N, int n){
        // code here
        vector<int> ans;
        int i=0;
        int a=1,b=2,c=3;
        solve(i,ans,N,n,a,c,b);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, n;
        cin>>N>>n;
        
        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends