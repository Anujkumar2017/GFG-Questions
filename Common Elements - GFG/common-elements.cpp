//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
        vector<int> common_element(vector<int>v1,vector<int>v2)
    {
        // Your code here
        vector<int> ans;
        map<int,int> a,b;
        int n=v1.size(),m=v2.size();
        
        for(int i=0;i<n;i++) 
            a[v1[i]]++;
            
        for(int j=0;j<m;j++) 
            b[v2[j]]++;
        
        for(auto x:a){
            int temp=x.first;
            if(b.find(temp)!=b.end()){
                int t=min(x.second,b.find(temp)->second);
                //cout<<t<<"\n";
                while(t--){
                    ans.push_back(temp);
                }
            }
        }
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int>v1(n,0);
        for(int i=0;i<n;i++)
        {
            cin>>v1[i];
        }
        int m;
        cin>>m;
        vector<int>v2(m,0);
        for(int i=0;i<m;i++)
        {
            cin>>v2[i];
        }
        Solution ob;
        vector<int>result;
        result=ob.common_element(v1,v2);
        for(auto i:result)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        
    }
}
// } Driver Code Ends