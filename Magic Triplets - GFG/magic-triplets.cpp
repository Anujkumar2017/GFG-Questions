//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>arr){
	    // Code here.
	    int n=arr.size();
	    int ans=0;
	    
	    for(int i=1;i<n-1;i++){
	        int l=0,r=0;
	        
	        // count the no of small number from current in left
	        for(int j=i-1;j>=0;j--){
	            if(arr[j]<arr[i]){
	                l++;
	            }
	        }
	        
	        // count the no of big number from current in right
	        for(int j=i+1;j<n;j++){
	            if(arr[j]>arr[i]){
	                r++;
	            }
	        }
	        //cout<<l<<" "<<r<<"\n";
	        ans+=l*r;
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends