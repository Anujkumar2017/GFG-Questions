//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    
    bool isValid(int i, int j, int n, int m){
        return (i>=0 && i<n && j>=0 && j<m);
    }
    
    void solve(int i, int j, int n, int m, int color,int newColor, vector<vector<int>>& vis, vector<vector<int>>& image){
        image[i][j]=newColor;
        vis[i][j]=1;
        for(int dir=0;dir<4;dir++){
            int x=i+dx[dir];
            int y=j+dy[dir];
            if(isValid(x,y,n,m) && !vis[x][y] && image[x][y]==color){
                solve(x,y,n,m,color,newColor,vis,image);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here
        int n=image.size(), m=image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int color=image[sr][sc];
        solve(sr,sc,n,m,color,newColor,vis,image);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends