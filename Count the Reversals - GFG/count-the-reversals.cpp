//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends



int countRev (string s)
{
    // your code here
    int n=s.size();
    stack<char> st;
    
    for(int i=0;i<n;i++){
        if(s[i]=='{')
            st.push(s[i]);
        else{
            if(!st.empty()){
                char ch=st.top();
                st.push(s[i]);
                if(ch=='{'){
                    st.pop();
                    st.pop();
                }
            }
            else{
                st.push(s[i]);
            }
        }
    }
    if(st.size()%2!=0){
        return -1;
    }else{
        int ans=0;
        while(st.size()>0){
            //cout<<st.top()<<" ";
            char a,b;
            
            a=st.top();
            st.pop();
            b=st.top();
            st.pop();
            
            if( (a=='{' && b=='{') || (a=='}' && b=='}') )
                ans+=1;
            else if(a=='{' && b=='}')
                ans+=2;
        }
        return ans;
    }
    
}