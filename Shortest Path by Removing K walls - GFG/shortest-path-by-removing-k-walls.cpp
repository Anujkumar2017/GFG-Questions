//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int shotestPath(vector<vector<int>> mat, int n, int m, int k) {
        // code here
        vector<vector<int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>> v(n,vector<int>(m,INT_MIN));
        
        queue<vector<int>> q;
        
        if(mat[0][0]==1){
            q.push({0,0,k-1});
            v[0][0]=k-1;
        }else{
            q.push({0,0,k});
            v[0][0]=k;
        }
        
        int count=0;
        while(!q.empty()){
            int p=q.size();
            while(p--){
                auto it =q.front();
                q.pop();
                if(it[0]==n-1 && it[1]==m-1){
                    return count;
                }
                
                for(int i=0;i<4;i++){
                    int x=it[0]+dir[i][0];
                    int y=it[1]+dir[i][1];
                    int c=it[2];
                    
                    if(x<n && y<m && y>=0 && x>=0){
                        if(v[x][y]<c){
                            if(mat[x][y]==0){
                                q.push({x,y,c});
                                v[x][y]=c;           
                            }else if(c>0){
                                q.push({x,y,c-1});
                                v[x][y]=c-1;
                            }
                        }
                    }
                }
            }
            count++;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends