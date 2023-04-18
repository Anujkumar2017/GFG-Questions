//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int n, string s, int k){
        // code here
        vector<int> v(n+2);
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                int x=i-k,y=i+k;
                x=max(0,x);
                y=min(y,n);
                v[x]++;
                v[y+1]--;
            }
        }
        for(int i=1;i<n;i++){
            v[i]+=v[i-1];
        }
        for(int i=0;i<n;i++){
            if(!v[i])
                return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends