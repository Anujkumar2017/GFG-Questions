//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    
    void findNslIdx(vector<long long>& v1, long long v2[], int n){
        stack<pair<long,long>> st;
        
        for(int i=0;i<n;i++){
            if(st.empty()){
                v1[i]=-1;
            }else if(!st.empty() && st.top().first<v2[i]){
                v1[i]=st.top().second;
            }else if(!st.empty() && st.top().first>=v2[i]){
                while(!st.empty() && st.top().first>=v2[i]){
                    st.pop();
                }
                if(st.empty())
                    v1[i]=-1;
                else 
                    v1[i]=st.top().second;
            }
            st.push({v2[i],i});
        }
    }
    
    void findNsrIdx(vector<long long>& v1, long long v2[], int n){
        stack<pair<long,long>> st;
        
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                v1[i]=n;
            }else if(!st.empty() && st.top().first<v2[i]){
                v1[i]=st.top().second;
            }else if(!st.empty() && st.top().first>=v2[i]){
                while(!st.empty() && st.top().first>=v2[i]){
                    st.pop();
                }
                if(st.empty())
                    v1[i]=n;
                else 
                    v1[i]=st.top().second;
            }
            st.push({v2[i],i});
        }
    }
    
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        long long ans=INT_MIN,area=0;
        vector<long long> nslIdx(n);   // nsl -- nearest smaller to left
        vector<long long> nsrIdx(n);   // nsr-- nearest smaller to right
        
        findNslIdx(nslIdx,arr,n);
        findNsrIdx(nsrIdx,arr,n);
        
        
        //reverse(nsrIdx.begin(),nsrIdx.end());
        
        // for(int i=0;i<n;i++){
        //     cout<<nslIdx[i]<<" ";
        // }
        // cout<<"\n";
        
        // for(int i=0;i<n;i++){
        //     cout<<nsrIdx[i]<<" ";
        // }
        // cout<<"\n";
        
        for(int i=0;i<n;i++){
            area= arr[i]*(nsrIdx[i]-nslIdx[i]-1);
            //cout<<area<<" ";
            ans=max(ans,area);
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends