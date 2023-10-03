//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
	int find_xor(int n)
	{
	    // Code here
	    int temp=n, cnt_1=0, cnt_0=0;
	    
	    while(temp>0){
	        if(temp&1)
	            cnt_1++;
	        else 
	            cnt_0++;
	        temp=temp>>1;
	    }
	    
	    return cnt_1^cnt_0;
	}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.find_xor(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends