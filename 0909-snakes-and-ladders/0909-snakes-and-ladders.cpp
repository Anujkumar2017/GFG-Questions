class Solution {
public:
     pair<int, int> coordinates(int x, int n){
        int r=n-(x-1)/n-1;
        int c = (x-1)%n;
        if(r%2==n%2)
            return {r,n-c-1};
        return {r, c};
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int steps=0;
        int n=board.size();
        queue<int> q;
        q.push(1);
        vector<vector<bool>> visited(n,vector<bool>(n));
        visited[n-1][0]=true;
        while(q.size()!=0){
            int z=q.size();
            for(int i=1;i<=z;i++){
                int x=q.front();
                if(x == n*n) 
                    return steps;
                q.pop();
                for(int j=1; j<=6; j++){
                    if(j+x > n*n) 
                        break;
                    pair<int, int> p = coordinates(x+j, n);
                    if(visited[p.first][p.second]) 
                        continue;
                    visited[p.first][p.second] = true;
                    if(board[p.first][p.second]!=-1)
                        q.push(board[p.first][p.second]);
                    else
                        q.push(j+x);
                }
            }
            steps++;
        }
        return -1;
    } 
};