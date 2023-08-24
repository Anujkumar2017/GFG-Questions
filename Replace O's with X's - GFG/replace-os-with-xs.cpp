//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    
    bool isValid(int i,int j, int n, int m){
        return (i>=0 && i<n && j>=0 && j<m);
    }

    void solve(int i, int j, int n, int m, vector<vector<char>>& mat, vector<vector<int>>& vis){
        // Mark current O visited
        vis[i][j]=1;
        
        for(int dir=0;dir<4;dir++){
            int x=i+dx[dir];
            int y=j+dy[dir];
            if(isValid(x,y,n,m) && !vis[x][y] && mat[x][y]=='O'){
                solve(x,y,n,m,mat,vis);
            }
        }
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int j=0;j<m;j++){
            //First row
            if(mat[0][j]=='O' && !vis[0][j]){
                solve(0,j,n,m,mat,vis);
            }
            
            //Last row
            if(mat[n-1][j]=='O' && !vis[n-1][j]){
                solve(n-1,j,n,m,mat,vis);
            }
        }
        
        for(int i=0;i<n;i++){
            //First column
            if(mat[i][0]=='O' && !vis[i][0]){
                solve(i,0,n,m,mat,vis);
            }
            
            //Last column
            if(mat[i][m-1]=='O' && !vis[i][m-1]){
                solve(i,m-1,n,m,mat,vis);
            }
        }
        
        // Make all non visited O's to X's
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O' and !vis[i][j]){
                    mat[i][j]='X';
                }
            }
        }
        
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends