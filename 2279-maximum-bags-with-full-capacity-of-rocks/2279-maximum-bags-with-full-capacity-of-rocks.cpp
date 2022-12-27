class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=capacity.size();
        for(int i=0;i<n;i++){
            capacity[i]-=rocks[i];
        }
        
        sort(capacity.begin(), capacity.end());
        int ans=0;
        for(int i=0;i<n;i++){ 
            // cout<<capacity[i]<<" "<<additionalRocks<<"\n";
            additionalRocks-=capacity[i];
            if(additionalRocks<0)
                break;
            // cout<<capacity[i]<<" "<<additionalRocks<<"\n";
            ans++;
        }
        return ans;
    }
};