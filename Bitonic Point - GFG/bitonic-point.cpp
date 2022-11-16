//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    // code here
	    int s=0;
	    int e=n-1;
	    int mid,ans;
	    
	    while(s<=e){
	        mid=s+(e-s)/2;
	        if(mid>0 && mid<n-1){
	             if(arr[mid-1]<arr[mid] && arr[mid+1]<arr[mid]){
	                ans=mid;
	                 break;
	             }
	             else if(arr[mid-1]>arr[mid])
	                e=mid-1;
	             else 
	                s=mid+1;     
	        }else{
	            if(mid==0 && arr[mid]>arr[mid+1]){
	                ans=mid;
	                break;
	            }else if(mid==n-1 && arr[mid]>arr[mid-1]){
	                ans=mid;
	                break;
	            }
	        }
	    }
	    
	    return arr[ans];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends