//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    string reverse(string str)
    { 
        //code here.
        int l=0, n=str.size();
        int r=n-1;
        while(l<r){
            if(!isalpha(str[l])){
                l++;
            }else if(!isalpha(str[r])){
                r--;
            }else{
                swap(str[l],str[r]);
                l++;
                r--;
            }
        }
        return str;
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.reverse(s) << endl;
    }
return 0;
}


// } Driver Code Ends