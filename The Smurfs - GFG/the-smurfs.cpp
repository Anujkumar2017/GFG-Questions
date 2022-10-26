//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findMin(int n, char a[]){
        // code here
        int rc,gc,bc;
        rc=gc=bc=0;
        for(int i=0;i<n;i++){
            if(a[i]=='R')
                rc++;
            else if(a[i]=='B')
                bc++;
            else if(a[i]=='G')
                gc++;
        }
        if(rc==n || gc==n || bc==n)
            return n;
        else if((rc%2==0 && bc%2==0 && gc%2==0 ) ||(rc%2==1 && bc%2==1 && gc%2==1 ))
            return 2;
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        cout<<ob.findMin(n, a)<<"\n";
    }
    return 0;
}
// } Driver Code Ends