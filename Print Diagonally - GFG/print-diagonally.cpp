//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int N, vector<vector<int>> A)
	{
		// Your code goes here
		map<int,vector<int>> mp;
		vector<int> ans;
		
		for(int i=0;i<N;i++){
		    for(int j=0;j<N;j++){
		            mp[i+j].push_back(A[i][j]);
		    }
		}
		for(auto x:mp){
		    //cout<<x.first<<" : ";
		    for(auto y:x.second){
		        //cout<<y<<" ";
		        ans.push_back(y);
		    }
		    //cout<<"\n";
		}
		
		return ans;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends