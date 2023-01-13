class Solution {
public:
    int dfs(vector<vector<int>> &graph, string &s, int &res, int i){
        int big1=0,big2=0;
        
        for(int &j:graph[i]){
            int curr=dfs(graph,s,res,j);
            if(s[i]==s[j]) 
                continue;
            if(curr>big2) big2=curr;
            if(big2>big1) swap(big2,big1);
        }
        res=max(res,big1+big2+1);
        return big1+1;
    }
    
    int longestPath(vector<int>& parent, string s) {
        int n=s.size(),res=0;
        vector<vector<int>> graph(n,vector<int>());
        
        for(int i=1;i<n;i++){
            graph[parent[i]].push_back(i);
        }
        dfs(graph,s,res,0);
        return res;
    }
};