//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    void solve(vector<int> &a, vector<int> &b, string &s){
        int p=0,q=0;
        for(int i=0;i<s.size();i++){
            if(i%2==0){
                while(a[p]==0)
                    p++;
                s[i]=p+'a';
                a[p]--;
            }else{
                while(b[q]==0)
                    q++;
                s[i]=q+'a';
                b[q]--;
            }
        }
    }
    
    string rearrange (string s, int N)
    {
        // your code here
        vector<int> v(26,0), c(26,0); 
        int cntV=0,cntC=0;
        
        for(int i=0;i<N;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                v[s[i]-'a']++;
                cntV++;
            }else{
                c[s[i]-'a']++;
                cntC++;
            }
        }
        
        if(abs(cntC-cntV)>1){
            return "-1";
        }
        
        if(cntV<cntC){
            solve(c,v,s);
        }else if(cntV>cntC){
            solve(v,c,s);
        }else{
            for(int i=0;i<26;i++){
                if(c[i]>0){
                    solve(c,v,s);
                    break;
                }
                if(v[i]>0){
                    solve(v,c,s);
                    break;
                }
            }
        }
        
        return s;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends