//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            // code here
            map<char,int> mp1,mp2;
            string s;
            int n,m;
            m=A.size();
            n=B.size();
            
            for(int i=0;i<m;i++)  
                mp1[A[i]]=1;
                
            for(int i=0;i<n;i++){  
                mp2[B[i]]=1;
            }
            
            for(int i=0;i<26;i++){
                char ch='a'+i;
                if( (mp1[ch]!=1 && mp2[ch]==1) || (mp2[ch]!=1 && mp1[ch]==1) )
                    s+=ch;
                //cout<<mp1[ch]<<" "<<mp2[ch]<<" "<<ch<<"\n";
            }
    
            if(s.size()==0)
                return "-1";
            return s;
        }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends