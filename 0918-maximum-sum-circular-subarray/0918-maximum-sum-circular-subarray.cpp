class Solution {
public:
    int Kadanes(vector<int> & nums){
        int n=nums.size();
        int maxi=INT_MIN,sum=0;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxi=max(sum,maxi);
            if(sum<0){
                sum=0;
            }
            
        }
        return maxi;
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int x=Kadanes(nums);
        int y=0;
        
        for(int i=0;i<nums.size();i++){
            y+=nums[i];
            nums[i]*=-1;
        }
        
        int z= Kadanes(nums);
        if(y+z==0) return x;
        return max(x,y+z);
    }
};