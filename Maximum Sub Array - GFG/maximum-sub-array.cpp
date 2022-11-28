//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    int i,j;
	    int mx=0,start=0,end=-1;
	    i=0,j=0;
	    int sum=0;
	    
	    while(j<n){
	        if(a[j]>=0){
	            sum+=a[j];
	            j++;
	        }else{
	            if(mx<sum){
	                mx=sum;
                    start=i;
                    end=j-1;
	            }
	            sum=0;
	            j++;
	            i=j;
	        }
	       // cout<<start<<" "<<end<<"\n";
	    }
	    
        if(mx<sum){
            sum=0;
            start=i;
            end=j-1;
        }
        
        vector<int> ans;
        // cout<<start<<" "<<end<<"\n";
        
        for(int i=start;i<=end;i++){
            ans.push_back(a[i]);
        }
        
        if(ans.size()==0)
            ans.push_back(-1);
            
        return ans;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends