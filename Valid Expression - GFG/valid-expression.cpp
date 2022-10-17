//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool valid(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<valid(str)<<endl;
    }
    return 0;
}
// } Driver Code Ends


bool valid(string s)
{
    // code here
    stack<char> st;
    int n=s.size();
    
    for(int i=0;i<n;i++){
        char ch=s[i];
        if(ch=='(' || ch=='{' || ch=='['){
            st.push(ch);
        }else{
            if(st.empty())
                return false;
            else{
                if(ch==')' && st.top()=='(')
                    st.pop();
                else if(ch=='}' && st.top()=='{')
                    st.pop();
                else if(ch==']' && st.top()=='[')
                    st.pop();
                else
                    return false;
            }
        }
    }
    if(st.empty())
        return true;
    else 
        return false;
}