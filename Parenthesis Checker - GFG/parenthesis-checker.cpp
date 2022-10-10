//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        // Your code here
        int n=s.size();
        stack<char> st;
        
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch=='{' || ch=='[' || ch=='('){
                st.push(ch);
            }
            else if(!st.empty() && (ch=='}' || ch==']' || ch==')') ){
                if(ch=='}' && st.top()=='{')
                    st.pop();
                else if(ch==')' && st.top()=='(')
                    st.pop();
                else if(ch==']' && st.top()=='[')
                    st.pop();
                else 
                    return false;
            }
            else if(st.empty() && (ch=='}' || ch==']' || ch==')'))
                return false;
        }
        if(st.empty())
            return true;
        else 
            return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends