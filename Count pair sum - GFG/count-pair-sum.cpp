//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    int countPairs(int arr1[], int arr2[],  int m, int n, int x) 
    { 
        //code here.
        int l=0, r=n-1;
        int cnt=0;
        
        while(l<m && r>=0){
            int sum=arr1[l]+arr2[r];
            if(sum>x){
                r--;
            }else if(sum<x){
                l++;
            }else {
                cnt++;
                l++;
            }
        }
        
        return cnt;
    } 
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m,n;
	    cin>>m>>n;
	    int arr1[m],arr2[n];
	    int x ;
	    for(int i=0;i<m;i++)
	        cin>>arr1[i];
	    for(int j=0;j<n;j++)
	        cin>>arr2[j];
	    cin>>x;
	    Solution ob;
	    cout <<ob.countPairs(arr1, arr2, m, n, x)<<endl;
	}
	return 0;	 
}


// } Driver Code Ends