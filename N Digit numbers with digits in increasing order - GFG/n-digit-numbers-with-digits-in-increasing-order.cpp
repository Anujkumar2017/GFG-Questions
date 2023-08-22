//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    void solve(int num,int idx, int n, vector<int>&ans){
        if(idx==n){
            ans.push_back(num);
            return;
        }
        for(int i=1;i<=9;i++){
            int dig=num%10;
            if(dig<i){
                 solve(num*10+i,idx+1,n,ans);
            }
        }
    }
    
    vector<int> increasingNumbers(int n)
    {
        // Write Your Code here
        vector<int> ans;
        if(n==1)
            ans.push_back(0);
        solve(0,0,n,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> ans = ob.increasingNumbers(N);
        for(auto num : ans){
            cout<< num <<" ";
        }
        cout<<endl;
        
    }
    return 0;
}
// } Driver Code Ends