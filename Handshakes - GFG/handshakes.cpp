//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int count(int n){
        // code here
        if(n==0)
            return 1;
        int cnt=0;
        for(int i=0;i<n;i+=2){
            cnt+=count(i)*count(n-2-i);
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.count(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends