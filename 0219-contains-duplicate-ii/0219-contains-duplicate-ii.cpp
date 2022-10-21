class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,vector<int>> mp;
        int n=nums.size();
        
        for(int i=0;i<n;i++) mp[nums[i]].push_back(i);
        
        // for(auto x:mp){
        //     cout<<x.first<<" : ";
        //     for(auto y:x.second)
        //         cout<<y<<" ";
        //     cout<<"\n";
        // }
        
        for(auto x:mp){
            for(int i=1;i<x.second.size();i++){
                if(abs(x.second[i]-x.second[i-1])<=k)
                    return true;
            }
        }
        return false;
    }
};