class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<string> temp;
        map<string,vector<int>> mp;
        int n=strs.size();
        temp=strs;
        
        for(int i=0;i<n;i++){
             sort(temp[i].begin(),temp[i].end());
        }
        
        for(int i=0;i<temp.size();i++){
            mp[temp[i]].push_back(i);
        }
        
        for(auto x:mp){
            vector<string> v;
            for(auto y:x.second){
                v.push_back(strs[y]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};