//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findHeight(int N, int arr[]){
        // code here
        int ans=0;
        for(int i=0;i<N;i++){
            // Parent of ith node
            int temp=arr[i];
            
            // Count level of ith node
            int cnt=1;
            
            // Count level till find parent -1 i.e. root node
            while(temp!=-1){
                temp=arr[temp];
                cnt++;
            }
            
            // max level is answer 
            ans=max(ans,cnt);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.findHeight(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends