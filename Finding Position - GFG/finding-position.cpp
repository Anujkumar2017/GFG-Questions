//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int solve(long long int n, int k){
        if(n==1)
            return k;
        solve(n/2,2*k);
    }
    
    long long int nthPosition(long long int n){
        // code here
        return solve(n,1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout<<ob.nthPosition(n)<<endl;
    }
    return 0;
}

// } Driver Code Ends