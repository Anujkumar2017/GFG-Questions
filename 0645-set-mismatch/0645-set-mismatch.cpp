class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int> mp;
        vector<int> ans;
        int sum=0,n=nums.size();
        
        sort(nums.begin(),nums.end());
        for(auto x:nums){
            mp[x]++;
            sum+=x;
        }
        
        for(auto x:mp){
            if(x.second==2)
                ans.push_back(x.first);
        }
        
        int diff=n*(n+1)/2-sum;
        
        ans.push_back(ans[0]+diff);
        
        return ans;
    }
};