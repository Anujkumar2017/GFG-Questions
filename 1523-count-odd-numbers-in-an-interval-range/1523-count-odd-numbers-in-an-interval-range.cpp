class Solution {
public:
    int countOdds(int low, int high) {
        int count=(high-low+1);
        int ans=count/2;
        if(count%2!=0){
            if(low%2!=0 || high%2!=0)
                ans++;
        }
        return ans;
    }
};