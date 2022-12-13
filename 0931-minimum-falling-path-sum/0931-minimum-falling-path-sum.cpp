class Solution {
public:
    int fun(int i,int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(j<0 || j>=matrix[0].size())
            return 1e7;
        if(i==0) 
            return matrix[0][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int  u=matrix[i][j]+fun(i-1,j,matrix,dp);
        int ld=matrix[i][j]+fun(i-1,j-1,matrix,dp);
        int rd=matrix[i][j]+fun(i-1,j+1,matrix,dp);
        // cout<<u<<" "<<ld<<" "<<rd<<"\n";
        
        dp[i][j]=min(u,min(ld,rd));
        return dp[i][j];
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int mini=1e7;
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        for(int j=0;j<m;j++){
            mini=min(mini,fun(n-1,j,matrix,dp));
        }
        return mini;
    }
};