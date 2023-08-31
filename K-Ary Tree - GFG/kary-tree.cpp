//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long mod=1e9+7;
    
    long long power(int x,int y){
        long long ans=1;
        while(y>0){
            if(y&1==1){ 
                ans=((ans%mod)*(x%mod))%mod;
                // ans=ans%mod;
            }
            y=y>>1;
            x=((x%mod)*(x%mod))%mod;
        }
        return ans%mod;
    }
    long long karyTree(int k, int m) {
        // code here
        return power(k,m)%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,m;
        
        cin>>k>>m;

        Solution ob;
        cout << ob.karyTree(k,m) << endl;
    }
    return 0;
}
// } Driver Code Ends