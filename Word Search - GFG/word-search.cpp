//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    
    bool isValid(int i, int j, int n, int m){
        return (i>=0 && i<n && j>=0 && j<m);
    }
    
    bool solve(int i, int j, int idx, int n, int m, vector<vector<char>>& mat, string w,
                    vector<vector<int>>& vis){
        if(idx==w.size()) return true;
        vis[i][j]=1;
        
        // cout<<i<<" "<<j<<"\n";
        
        for(int dir=0;dir<4;dir++){
            int x=i+dx[dir];
            int y=j+dy[dir];
            if(isValid(x,y,n,m) && !vis[x][y] && mat[x][y]==w[idx]){
                if(solve(x,y,idx+1,n,m,mat,w,vis))
                    return true;
            }
        }
        vis[i][j]=0;
        return false;
        
    }
    
    bool wordSearch(vector<vector<char>>& mat, string w) {
        //code here
        int n=mat.size(), m=mat[0].size();
        vector<vector<int>>  vis(n,vector<int>(m,0));
        
        int idx=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==w[idx]){
                    if(solve(i,j,idx+1,n,m,mat,w,vis))
                        return true;
                }
            }
        }
        return false;
    }

};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<char>> mat(n,vector<char>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>mat[i][j];
            }
        }
        string str; cin>>str;
        Solution ob;
        auto ans=ob.wordSearch(mat,str);
        cout<<ans<<"\n";
    }
    return 0;
}

// } Driver Code Ends