//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findNth(int n){
        // code here
        int pos=0;
        
        while(n!=0){
            if(n&(1)){
                return pos;
            }
            pos++;
            n>>=1;
        }
        
        return pos;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.findNth(n) << endl;
    }
    return 0;
}

// } Driver Code Ends