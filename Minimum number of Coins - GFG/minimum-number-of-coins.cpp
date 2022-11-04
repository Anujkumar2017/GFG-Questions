//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int n)
    {
        // code here
        vector<int> ans;
        vector<int> currency={1,2,5,10,20,50,100,200,500,2000};
        for(int i=9;i>=0;i--){
            int cnt=(n/currency[i]),temp;
            temp=cnt;
            while(temp){
                ans.push_back(currency[i]);
                temp--;
            }
            cnt=n/currency[i];
            n=n-cnt*currency[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends