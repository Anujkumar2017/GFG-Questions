//{ Driver Code Starts
// Initial Template for C++

// Initial Template for C++
// Back-end complete function Template for C++
// User function Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int gcd(int a , int b)
    {
       if(b==0) 
         return a;
       return gcd(b,a%b);
    }
    
    long long lcmTriplets(long long n) {
        // code here
        // ans=odd*even*odd;
        long long ans;
        
        if(n==1 || n==2)
            return n;
            
        if(n%2!=0){
            //Ex-9,8,7
            ans=n*(n-1)*(n-2);
        }
        else {
            //Ex- 10,9,8,7
            if(gcd(n,n-3)==1){
                // even*odd*odd
                ans=(n)*(n-1)*(n-3);
            }else{
                //Ex- 12,11,10,9     if(n%3==0)
                ans=(n-1)*(n-2)*(n-3);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.lcmTriplets(N) << "\n";
    }
}
// } Driver Code Ends