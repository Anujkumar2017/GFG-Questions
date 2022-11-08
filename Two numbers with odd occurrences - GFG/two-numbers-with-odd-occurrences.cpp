//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        vector<long long int> v;
        long long int first=0,second=0,x=0;
        
        for(long long int i=0;i<N;i++){
            x=x^Arr[i];
        }
        
        long long int setbit= x & ~(x-1);   // right most set bit two differentiate
        
        for(int i=0;i<N;i++){
            if(setbit & Arr[i]){
                first^=Arr[i];
            }else
                second^=Arr[i];
        }
        
        v.push_back(first);
        v.push_back(second);
        sort(v.begin(),v.end(),greater<int>());
        
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends