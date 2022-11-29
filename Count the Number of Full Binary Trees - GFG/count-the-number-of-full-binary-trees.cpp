//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    
    long long int numoffbt(long long int arr[], int n){
        // Your code goes here
        long long int  mn=INT_MAX;
        long long int mx=INT_MIN;
        long long int mod = 1e9+7;
        
        for(int i=0;i<n;i++){
            mx=max(mx,arr[i]);
            mn=min(mn,arr[i]);
        }
        
        long long int dp[mx+1]={0};
        
        for(int i=0;i<n;i++){
            dp[arr[i]]=1;
        }
        
        long long int ans=0;
        
        for(int i=mn;i<=mx;i++){
             if(dp[i]!=0){
                 for(int j=2*i;j<=mx && j/i<=i;j+=i){
                     if(dp[j]!=0){
                         dp[j]+=dp[i]*dp[j/i];
                         if(i!=(j/i)){
                             dp[j]+=dp[i]*dp[j/i];
                         }
                     }
                 }
                 ans+=dp[i]%mod;
             }
        }
        return ans%mod;
        
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<<ob.numoffbt(a,n)<<endl;
		
	}
	return 0;
}


// } Driver Code Ends