//{ Driver Code Starts
#include <bits/stdc++.h>


using namespace std;




// } Driver Code Ends

class Solution{
  public:
    int Countpair(int arr[], int n, int target){
        
        // Complete the function
        int l=0;
        int r=n-1;
        int cnt=0;
        
        while(l<r){
            int sum=arr[l]+arr[r];
            if(sum>target)
                r--;
            else if(sum<target)
                l++;
            else{
                cnt++;
                l++;
            }
        }
        
        return cnt==0 ? -1 : cnt;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        int arr[n+1];
        
        for(int i=0;i<n;i++)
        cin>>arr[i];

        int sum;
        cin>>sum;
        Solution obj;
        cout << obj.Countpair(arr, n, sum) << endl;
        
    }
	return 0;
}

// } Driver Code Ends