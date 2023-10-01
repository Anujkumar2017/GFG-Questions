//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int maxDiffIndex(int a[], int N)
    {
        unordered_map<int, int> mp;
        int ans=0;
        
        for(int i=0; i<N; i++){
            if(mp.find(a[i])!=mp.end()){
                ans=max(ans,i-mp[a[i]]);
            }else 
                mp[a[i]]=i;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
     int t;
     cin>>t;
     while(t--)
     {
         int n;
         cin>>n;
         int a[n];
         for(int i=0;i<n;i++)
            cin>>a[i];
         Solution ob;
         cout<<ob.maxDiffIndex(a, n)<<"\n";
     }
	return 0;
}
// } Driver Code Ends