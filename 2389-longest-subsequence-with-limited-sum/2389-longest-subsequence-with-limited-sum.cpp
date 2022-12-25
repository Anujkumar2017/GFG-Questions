class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size(),m=queries.size();
        vector<int> ans;
        
        sort(nums.begin(),nums.end());
        vector<int> preSum(nums.size(),0);
        preSum[0]=nums[0];
        
        for(int i=1;i<n;i++){
            preSum[i]=preSum[i-1]+nums[i];    
        }
        
        for(int i=0;i<m;i++){
            int query=queries[i];
            int ele=upper_bound(preSum.begin(),preSum.end(),query)-preSum.begin();
            ans.push_back(ele);
        }
        
        return ans;
    }
};