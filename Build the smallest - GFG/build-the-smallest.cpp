//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    //code here.
    stack<char> st;
    st.push(num[0]);
    for(int i=1;i<num.size();i++){
        while(!st.empty() && st.top()>num[i] && k>0){
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    while(k>0){
        st.pop();
        k--;
    }
    
    string ans;
    while(!st.empty()){
        ans=st.top()+ans;
        st.pop();
    }

    int l=-1;
    for(int i=0;i<ans.size();i++){
        if(ans[i]!='0'){
            break;
        }
        l=i;
    }
    // cout<<ans<<" "<<l<<"\n";
    
    if(l==ans.size()-1) 
        return "0";
    else if(l>=0) 
        return ans.substr(l+1);
    return ans;
}