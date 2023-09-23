//{ Driver Code Starts
#include <iostream>
using namespace std;

long long int longestSubarry(long long int *arr, long long int n);

// Driver code
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << longestSubarry(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends


long long int longestSubarry(long long int A[], long long int N) {
    long long int ans=0,j=0,mx=0;
    
    while(j<N){
        if(A[j]>0){
            mx++;
        }else 
            mx=0;
        
        ans=max(ans,mx);    
        j++;
    }
    
    return ans;
}