//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

    public:
    bool isValid(int x, int y, int m, int n){
        return (x>=0 && x<m && y>=0 && y<n);
    }
    
    vector<vector<int> > findDistance(vector<vector<char> >& mat, int m, int n) 
    { 
        // Your code goes here
        vector<vector<int>> ans(m,vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]=='W'){
                    ans[i][j]=-1;
                }else if(mat[i][j]=='B'){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        int dx[4]={-1,0,1,0};
	    int dy[4]={0,1,0,-1};
	    
	    while(!q.empty()){
	        int size=q.size();
	        while(size--){
	            auto temp=q.front();
	            q.pop();
	            
	            int x=temp.first;
	            int y=temp.second;
	            
	            for(int dir=0; dir<4; dir++){
	                int xx=x+dx[dir];
	                int yy=y+dy[dir];
	                
	                if(isValid(xx,yy,m,n) && mat[xx][yy]=='O'){
	                    if(ans[xx][yy]>ans[x][y]+1){
	                        ans[xx][yy]=ans[x][y]+1;
	                        q.push({xx,yy});
	                    }
	                }
	            }
	        }
	    }
	    
	    for(int i=0; i<m; i++){
	        for(int j=0; j<n; j++){
	            if(ans[i][j]==INT_MAX)
	                ans[i][j]=-1;
	        }
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
    	int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M,N); 
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}
// } Driver Code Ends