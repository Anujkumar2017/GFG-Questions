//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool isValid(int i, int j, int n, int m){
        return (i<n && i>=0 && j<m && j>=0);
    }
    int Count(vector<vector<int> >& mat) {
        // Code here
        int n=mat.size(),m=mat[0].size();
        int dx[]={-1,-1,0,1,1,1,0,-1};
        int dy[]={0,1,1,1,0,-1,-1,-1};
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    int zeros=0;
                    for(int k=0;k<8;k++){
                        int x=i+dx[k];
                        int y=j+dy[k];
                        if(isValid(x,y,n,m) && mat[x][y]==0){
                            zeros++;
                        }
                    }
                    // cout<<"zeros "<<zeros<<"\n";
                    if(zeros%2==0 && zeros>0)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends