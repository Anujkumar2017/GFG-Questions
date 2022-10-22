//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int fillingBucket(int N) {
        // code here
        int mod=1e8;
        int fill[100001];
        fill[0]=fill[1]=1;
        
        for(int i=2;i<=N;i++){
            fill[i]=(fill[i-1]+fill[i-2])%mod;
            //cout<<fill[i]<<" ";
        }
        return fill[N];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends