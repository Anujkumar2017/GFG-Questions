//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
	    // Your code goes here
	    sort(arr,arr+n);
	    int cnt=0;
	    
	    for(int i=n-1; i>=0; i--){
	        int l=0;
	        int r=i-1;
	        while(l<r){
	            int sum=arr[l]+arr[r];
	           // cout<<sum<<" ";
	            if(sum>arr[i]){
	                r--;
	            }else if(sum<arr[i]){
	                l++;
	            }else{
	                cnt++;
	                l++;
	            }
	        }
	       // cout<<"\n";
	    }
	    
	    return cnt;
	}
};

//{ Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}
// } Driver Code Ends