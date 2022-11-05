//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxGroupSize(int arr[], int n, int k) {
        // code here
        map<int,int> mp;
        
        for(int i=0;i<n;i++){
            mp[arr[i]%k]++;
        }
        int ans=0;
        for(int i=0;i<=k/2;i++){
            if(mp[i]>=1){
                if(i==0)
                    ans++;
                else if(i==k/2 && k%2==0)
                    ans++;
                else 
                    ans+=max(mp[i], mp[k-i]);
            }
            else if(mp[k-i]>=1)
                ans+=mp[k-i];
                
            //cout<<i<<" "<<mp[i]<<" "<<ans<<"\n";
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends