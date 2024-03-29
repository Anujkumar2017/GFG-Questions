//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        if(n==1)
            return 1;
        
        long long prefix[n],suffix[n];
        prefix[0]=a[0];
        suffix[n-1]=a[n-1];
        
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+a[i];
        }
        
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+a[i];
        }
        
        int ans=-1;
        for(int i=2;i<n-1;i++){
            if(prefix[i-1]==suffix[i+1])
                ans=i+1;        
        }
        return ans;
    }

};


//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends