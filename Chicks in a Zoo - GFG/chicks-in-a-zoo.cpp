//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long int NoOfChicks(int n){
	    // Code here
	    long long chick[n],chicks=1;
	    chick[0]=0;
	    chick[1]=1;
	    for(long long i=2;i<=n;i++){
	        if(i>6) chicks-=chick[i-6];
	        chick[i]=chicks*2;
	        chicks+=chick[i];
	    }
	    return chicks;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends