//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxDistinctNum(int arr[], int n, int k)
    {
    	// Complete the function
    	map<int,int> mp;
    	priority_queue<int> pq;
    	
    	for(int i=0; i<n; i++){
    	    mp[arr[i]]++;
    	}
    	
    	for(auto x:mp){
    	    pq.push(x.second);
    	}
    	
    	while(k--){
    	    int top=pq.top();
    	    pq.pop();
    	    if(top>1){
    	       pq.push(top-1);
    	    }
    	}
    	
    	return pq.size();
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i,k;
	cin>>n>>k;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout <<ob.maxDistinctNum(arr, n, k)<<"\n";
	  }
	return 0;
}

// } Driver Code Ends