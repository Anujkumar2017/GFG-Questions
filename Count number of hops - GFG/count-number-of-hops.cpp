//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        // your code here
        if(n==1)
            return 1;
        else if(n==2)
            return 2;
        else if(n==3)
            return 4;
            
        vector<long long> ways(n+1,0);
        long long mod=1e9+7;
        
        ways[1]=1;
        ways[2]=2;
        ways[3]=4;
        
        for(int i=4;i<=n;i++){
            ways[i]=(ways[i-1]%mod+ways[i-2]%mod+ways[i-3]%mod)%mod;
        }
        //cout<<ways[n]<<"\n";
        return ways[n]%mod;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends