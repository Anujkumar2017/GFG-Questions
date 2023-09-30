//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int count_tabs(string arr[], int n)
    {
        // Complete the function
        unordered_map<string, int> mp;
        
        for(int i=0; i<n; i++){
            if(arr[i]=="END"){
                mp.clear();
            }else if(mp.find(arr[i])!=mp.end()){
                mp.erase(arr[i]);
            }else 
                mp[arr[i]]++;
        }
        
        return mp.size();
    }
};


//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>> n;
	    string arr[n+1];
	    
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	   Solution ob;
	   cout << ob.count_tabs(arr, n) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends