//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int count(int N, vector<int> A,int X)
    {
        // code here
        int ans=N;
        int bitsetinX=0;
        
        for(int i=30;i>=0;i--){
            if(X&(1<<i)){
                //useless
                bitsetinX=bitsetinX|(1<<i);
            }else{
                int temp= bitsetinX|(1<<i);
                
                int donotmodify=0;
                for(int number:A){
                    if((temp&number)==temp){
                        donotmodify++;
                    }
                }
                ans=min(ans,N-donotmodify);
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int N,X;
        cin>>N>>X;
        vector<int> A(N);
        for(auto &i:A)
            cin>>i;
        Solution obj;
        int ans = obj.count(N, A, X);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends