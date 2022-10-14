//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        //code here.
        string ans,temp;
        stack<char> st;
        int n=s.size();
        
        for(int i=0;i<n;i++){
            if(s[i]!='.'){
                st.push(s[i]);
            }else{
                temp="";
                while(!st.empty()){
                    temp+=st.top();
                    st.pop();
                }
                ans+=temp;
                ans+='.';
            }
            //cout<<temp<<"\n";
        }
        temp="";
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }
        ans+=temp;
        
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
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends