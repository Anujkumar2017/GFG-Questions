class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> mp;
        int ans=0;
        
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        
        for(auto x:mp){
            if(x.second==1)
                return -1;
            else if(x.second%3==0){
                ans+=x.second/3;
            }else 
                ans+=x.second/3+1;
        }
        
        return ans;
    }
};