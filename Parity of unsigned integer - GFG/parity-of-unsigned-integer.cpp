//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string computeParity(int N) {
        // code here
        int cnt=0;
        while(N){
            if(N&1)
                cnt++;
            N=N>>1;
        }
        
        if(cnt%2==0)
            return "even";
            
        return "odd";
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
        cout << ob.computeParity(N) << endl;
    }
    return 0;
}
// } Driver Code Ends