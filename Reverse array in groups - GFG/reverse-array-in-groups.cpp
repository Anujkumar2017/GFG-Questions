//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long>& arr, int n, int k){
        // code here
        for(int i=0;i<n;i++){
            if(i%k==0 && i!=0){
                reverse(arr.begin()+i-k,arr.begin()+i);
                //cout<<i<<"\n";
            }
        }
        if(n%k==0){
            reverse(arr.end()-k,arr.end());
        }else{
            reverse(arr.end()-n%k,arr.end());
        }
        // for(int i=0;i<n;i++){
        //     cout<<arr[i]<<"\n";
        // }
    }
};

//{ Driver Code Starts.
int main() {
    int t; 
    cin >> t; 
    while(t--){ 
        int n;
        cin >> n; 
        vector<long long> arr; 
        int k;
        cin >> k; 

        for(long long i = 0; i<n; i++)
        {
            long long x;
            cin >> x; 
            arr.push_back(x); 
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);
        
        for(long long i = 0; i<n; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends