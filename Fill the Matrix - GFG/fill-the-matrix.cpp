//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int n, int m, int x, int y){    
        // code here
        int mat[n][m];
        memset(mat,0,sizeof(mat));
        x--;
        y--;
        mat[x][y]=1;
        int ans=0;
        int r[4]={-1,0,0,1};
        int c[4]={0,1,-1,0};
        queue<pair<pair<int,int>,int>>q;
        q.push({{x,y},0});
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int cnt=q.front().second;
            ans=cnt;
            for(int i=0;i<4;i++){
                int trow=row+r[i];
                int tcol=col+c[i];
                if(trow<0 || tcol<0 ||trow>=n ||tcol>=m) continue;
                if(mat[trow][tcol]==0){
                    q.push({{trow, tcol},cnt+1});
                    mat[trow][tcol]=1;
                }
            }
            q.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends