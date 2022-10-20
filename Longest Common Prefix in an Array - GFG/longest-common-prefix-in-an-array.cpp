//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  
    bool compare(string s1,string s2){
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i])
                return false;
        }
        return true;
    }  
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        int mn=INT_MAX,indx=-1;
        string temp;
        
        for(int i=0;i<N;i++){
            if(mn>arr[i].size()){
                mn=arr[i].size();
                indx= i;
            }
        }
        
        for(int i=0;i<mn;i++){
            temp= arr[indx].substr(0,mn-i);
            //cout<<temp<<" ";
            bool match=true;
            for(int i=0;i<N;i++){
                if(compare(temp,arr[i])==false)
                    match=false;
            }
            if(match)
                return temp;
        }
        
        return "-1";
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends