//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here
        vector<int> ans;
        int l=0,k=0;
        
        while(l<r && k<c){
            // first row
            for(int i=l;i<c;i++){
                ans.push_back(matrix[l][i]);
            }
            l++;
            
            // last column 
            for(int i=l;i<r;i++){
                ans.push_back(matrix[i][c-1]);
            }
            c--;
            
            // last row
            if(l<r){
                for(int i=c-1;i>=k;i--){
                    ans.push_back(matrix[r-1][i]);
                }
                r--;
            }
            
            // first col
            if(k<c){
                for(int i=r-1;i>=l;i--){
                    ans.push_back(matrix[i][k]);
                }
                k++;
            }
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
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends