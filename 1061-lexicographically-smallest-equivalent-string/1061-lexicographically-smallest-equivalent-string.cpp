class Solution {
public:
    int par[26];
    
    int find(int x){
        if(par[x]==-1) return x;
        return par[x]=find(par[x]);
    }
    
    void Union(int x,int y){
        x=find(x);
        y=find(y);
        
        if(x!=y){
            par[max(x,y)]=min(x,y);
        }
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        memset(par,-1,sizeof par);
        
        for (int i = 0; i < s1.size(); i++) 
            Union(s1[i] - 'a', s2[i] - 'a');
        
        string ans;
        for(int i=0;i<baseStr.size(); i++) 
            ans+=find(baseStr[i]-'a')+'a';
        return ans;
    }
};