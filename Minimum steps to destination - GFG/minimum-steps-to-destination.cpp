//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minSteps(int D){
        // code here
        int step=1;
        long long int sum=0;
        
        while(sum<D){
            sum+=step;
            step++;
        }
        
        if((sum-D)%2==0)
            return step-1;
        else if((sum+step-D)%2==0)
            return step;
        else 
            return step+1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int D;
        cin>>D;
        
        Solution ob;
        cout<<ob.minSteps(D)<<"\n";
    }
    return 0;
}
// } Driver Code Ends