class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans=0;
        int col=strs[0].size();
        int row=strs.size();
        
        for(int j=0;j<col;j++){
            for(int i=0;i<row-1;i++){
                if(strs[i][j]>strs[i+1][j]){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};