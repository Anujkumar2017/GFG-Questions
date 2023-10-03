//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long nearestPowerOf2(long long N){
        //code here
        long long num=1;
        
        while(num<N){
            num*=2;
        }
        
        return num;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.nearestPowerOf2(N)<<"\n";
    }
}
// } Driver Code Ends