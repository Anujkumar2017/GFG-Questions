//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int onlyFirstAndLastAreSet(long long int n) { 
	    //complete the function here
	    if(n%2==0)
	        return 0;
	    return ((n-1)& (n-2))==0;
	}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        Solution ob;
        cout << ob.onlyFirstAndLastAreSet(n) << endl;
    }
    
return 0;
}


// } Driver Code Ends