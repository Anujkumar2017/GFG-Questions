//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
  public:
    int findDiff(int arr[], int n) {
        int mn=INT_MAX;
        int mx=INT_MIN;
        unordered_map<int,int> mp;
        
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        
        for(auto it:mp){
            mn=min(mn,it.second);
            mx=max(mx,it.second);
        }
        
        // cout<<mn<<" "<<mx<<"\n";
        return mx-mn;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n], i;
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.findDiff(arr, n) << "\n";
    }
    return 0;
}

// } Driver Code Ends