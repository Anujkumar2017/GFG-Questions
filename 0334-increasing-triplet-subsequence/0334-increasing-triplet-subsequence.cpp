class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> smaller(n);
        vector<int> bigger(n);
        
        int min=0;
        smaller[0]=-1;
        for(int i=0;i<n;i++){
            if(nums[i]<=nums[min]){
                min=i;
                smaller[i]=-1;
            }else 
                smaller[i]=min;
        }
        
        int max=n-1;
        bigger[max]=-1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]>=nums[max]){
                max=i;
                bigger[i]=-1;
            }else 
                bigger[i]=max;
        }
        
        // for(int i=0;i<n;i++){
        //     cout<<smaller[i]<<" ";
        // }
        // cout<<"\n";
        // for(int i=0;i<n;i++){
        //     cout<<bigger[i]<<" ";
        // }
        
        for(int i=0;i<n;i++){
            if(smaller[i]!=-1 && bigger[i]!=-1)
                return true;
        }
        return false;
    }
};