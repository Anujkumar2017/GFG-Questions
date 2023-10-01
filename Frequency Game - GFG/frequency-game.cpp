//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        // code here
        unordered_map<int,int> mp;
        int mn=INT_MAX;
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        
        for(auto it:mp){
            mn=min(mn,it.second);
        }
        
        // cout<<mn<<"\n";
        
        int ans=0;
        for(auto it:mp){
            // cout<<it.first<<" "<<it.second<<"\n";
            if(it.second==mn){
                ans=max(ans,it.first);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends