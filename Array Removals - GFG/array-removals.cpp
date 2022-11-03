//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& arr, int k){
        //Code here
        // TC: O(n*logn);
        
        sort(arr.begin(),arr.end());
        int n=arr.size(),ans=INT_MAX;
        
        for(int i=0;i<n;i++){
            int low=i;
            int high = lower_bound(arr.begin(),arr.end(),arr[i]+k)-arr.begin();
            //cout<<low<<" "<<high<<"\n";
            if(arr[high]-arr[low]==k)
                ans=min(ans,n-(high-low+1));
            else 
                ans=min(ans,n-(high-low));
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends