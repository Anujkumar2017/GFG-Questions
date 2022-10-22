//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        // code here
        vector<int> ans;
        int k,l;
        k=l=0;
        
        while(k<R && l<C){
            /*printing first row from remaining rows*/
            for(int i=l;i<C;i++) 
                ans.push_back(a[k][i]);
            k++;
            
            /*printing first column from remaining column*/
            for(int i=k;i<R;i++)
                ans.push_back(a[i][C-1]);
            C--;
            
            /*printing last row from remaining rows*/
            if(k<R){
                for(int i=C-1;i>=l;i--)
                    ans.push_back(a[R-1][i]);
                R--;
            }
            
            /*printing last column from remaining column*/
            if(l<C){
                for(int i=R-1;i>=k;i--)
                    ans.push_back(a[i][l]);
                l++;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends