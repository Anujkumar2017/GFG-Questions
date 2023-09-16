//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        map<char,int> mp;
        priority_queue<int> pq;
        
        for(auto ch:s){
            mp[ch]++;
        }
        
        for(auto it:mp){
            pq.push(it.second);
        }
        
        while(k--){
            int temp=pq.top();
            pq.pop();
            pq.push(temp-1);
        }
        
        int ans=0;
        while(!pq.empty()){
            int x=pq.top();
            ans+=x*x;
            pq.pop();
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends