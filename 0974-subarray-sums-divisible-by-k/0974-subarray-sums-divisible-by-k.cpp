class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0, ans=0;
        map<int,int> mp;
        mp[0]=1;
        
        for(auto x:nums){
            sum=((sum+x)%k+k)%k;
            mp[sum]++;
            if(mp[sum]>1){
                ans+=mp[sum]-1;
            }
        }
        return ans;
    }
};