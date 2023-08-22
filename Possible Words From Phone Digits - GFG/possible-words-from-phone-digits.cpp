//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    void solve(string s, int idx, int n, int a[], vector<string>& ans, map<int,string> mp){
        if(idx==n){
            ans.push_back(s);
            return;
        }
        // cout<<ans.size()<<"\n";
        string str=mp[a[idx]];
        for(int i=0;i<str.size();i++){
            solve(s+str[i],idx+1,n,a,ans,mp);
        }
    }
    
    vector<string> possibleWords(int a[], int n)
    {
        //Your code here
        vector<string> ans;
        map<int,string> mp={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},
                                            {7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
        solve("",0,n,a,ans,mp);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends