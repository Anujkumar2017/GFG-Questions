//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

long long int maxSumWithK(long long int a[], long long int n, long long int k);

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        cout << maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends


long long int maxSumWithK(long long int arr[], long long int n, long long int k) 
{
    int maxSum[n];
    int csum=arr[0];
    
    maxSum[0]=csum;
    
    for(int i=1; i<n; i++){
        if(csum>0){
            csum+=arr[i];
        }else{
            csum=arr[i];
        }
        maxSum[i]=csum;
    }
    
    int ans=INT_MIN;
    int exactK=0;
    
    for(int i=0; i<k; i++){
        exactK+=arr[i];
    }
    
    if(ans<exactK){
        ans=exactK;
    }
    
    for(int i=k; i<n; i++){
        exactK+=arr[i];
        exactK-=arr[i-k];
        
        if(ans<exactK){
            ans=exactK;
        }
        
        int atLeastK=maxSum[i-k]+exactK;
        
        if(ans<atLeastK){
            ans=atLeastK;
        }
    }
    
    return ans;
}