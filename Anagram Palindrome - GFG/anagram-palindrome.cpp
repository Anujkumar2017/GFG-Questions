//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int isPossible (string s);

int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		if (isPossible (s))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int isPossible (string S)
{
    // your code here
    unordered_map<char,int> map;
    for(auto ch:S){
        map[ch]++;
    }
    
    int cnt=0;
    for(auto it: map){
        if(it.second%2!=0){
            cnt++;
            if(cnt>1){
                return false;
            }
        }
    }
    
    return true;
}