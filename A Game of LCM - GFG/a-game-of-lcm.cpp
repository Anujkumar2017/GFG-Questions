//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long maxGcd(int N) {
        // code here
        long long x=N*(N-1)/__gcd(N,N-1);
        long long y=(N-2)*(N-3)/__gcd(N-2,N-3);
        long long z=x*y/__gcd(x,y);
        
        long long num=N*(N-1),cnt=0;
        for(long long i=N-2;i>0;i--){
            if(__gcd(num,i)==1){
                num*=i;
                cnt++;
            }
            if(cnt==2){
                break;
            }
        }
        return max(z,num);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.maxGcd(N) << "\n";
    }
}
// } Driver Code Ends