//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        // Your code here
        bool ans=false;
        map<char,int> mp,tp;
        if(a.size()==b.size()){
            for(int i=0;i<a.size();i++){
                mp[a[i]]++;
                tp[b[i]]++;
            }   
            if(mp==tp){
                ans=true;
            }
        }
        return ans;
        
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends