//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*Returns an array of all n-bit gray codes sequence.
You are required to complete below method. */
class Solution{
  public:
    vector <string> generateCode(int N)
    {
         //Your code here
         if(N==1)
            return {"0", "1"};
        
        vector<string> prev=generateCode(N-1);
        vector<string> ans;
        
        for(int i=0; i<prev.size(); i++){
            ans.push_back("0"+prev[i]);
        }
        
        for(int i=prev.size()-1; i>=0; i--){
            ans.push_back("1"+prev[i]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution obj;
		vector <string> res = obj.generateCode(n);
		for (string i : res) cout << i << " ";
        cout<<endl;
	}
	return 0;
}


// } Driver Code Ends