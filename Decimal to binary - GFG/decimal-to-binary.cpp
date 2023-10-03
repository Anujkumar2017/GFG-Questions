//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

void toBinary(int N)
{
    // your code here
    vector<int> v;
    
    while(N>0){
        v.push_back(N%2);
        N/=2;
    }
    
    for(int i=v.size()-1; i>=0; i--){
        cout<<v[i];
    }
        
}

//{ Driver Code Starts.

int main() {
	//code
	
	int t;
	cin>>t;
	
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    toBinary(n);
	    cout<<endl;
	}
	return 0;
}
// } Driver Code Ends