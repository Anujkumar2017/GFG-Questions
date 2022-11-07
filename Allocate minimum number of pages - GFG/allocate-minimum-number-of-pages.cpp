//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    // function to check valid mid
    bool isValid(int A[], int N, int max_limit, int M){
        int cnt=1;
        int curr_sum=0;
        
        for(int i=0;i<N;i++){
            if(curr_sum+A[i]<=max_limit){
                curr_sum+=A[i];
            }else{
                cnt++;
                curr_sum=A[i];
            }
            if(cnt>M)
                return false;
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        /* Steps-
            1.select mid between low and high
            2.if mid is valid high=mid-1
            3.else mid=low+1
        */
        if(N<M){
            return -1;
        }
        
        int max_limit=0,low,high,res;
        
        for(int i=0;i<N;i++){
            max_limit+=A[i];
        }
        
        low=*max_element(A,A+N);
        high=max_limit;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(isValid(A,N,mid,M)){
                res=mid;
                high=mid-1;
            }
            else
                low=mid+1;
            //cout<<mid<<" ";    
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends