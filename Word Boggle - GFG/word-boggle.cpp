//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int dx[8]={-1,-1,0,1,1,-1,0,1};
    int dy[8]={0,1,1,1,0,-1,-1,-1};
    
    bool isValid(int i, int j, int n, int m){
        return (i>=0 && i<n && j>=0 && j<m);
    }
    
    bool solve(int i, int j, int idx, int n, int m, vector<vector<char>>& mat, string w,
                    vector<vector<int>>& vis){
        if(idx==w.size()) return true;
        vis[i][j]=1;
        
        // cout<<i<<" "<<j<<"\n";
        
        for(int dir=0;dir<8;dir++){
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
    
    bool isWordExist(vector<vector<char>>& mat, string w) {
        //code here
        int n=mat.size(), m=mat[0].size();
        vector<vector<int>>  vis(n,vector<int>(m,0));
        
        int idx=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==w[idx] && !vis[i][j]){
                    if(solve(i,j,idx+1,n,m,mat,w,vis))
                        return true;
                }
            }
        }
        return false;
    }
    
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    // Code here
	    vector<string> ans;
	    for(int i=0;i<dictionary.size();i++){
	        string word=dictionary[i];
	        if(isWordExist(board,word)==true)
	            ans.push_back(word);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends