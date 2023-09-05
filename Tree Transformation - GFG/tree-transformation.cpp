//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int solve(int n, vector<int> p){
        // code here
        vector<int> degree(n+1);
        for(int i=1;i<n;i++){
            degree[i]++;
            degree[p[i]]++;
        }
        
        int cnt=0;
        for(int i=0;i<n;i++){
            if(degree[i]==1){
                cnt++;
            }
        }
        int ans=(n-1)-cnt;
        
        return ans>0? ans:0;
        
    }
};


//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> p(N);
        for(int i = 0; i < N; i++){
            cin >> p[i];
        }

        Solution obj;
        cout << obj.solve(N, p) << "\n";
    }
}   
// } Driver Code Ends