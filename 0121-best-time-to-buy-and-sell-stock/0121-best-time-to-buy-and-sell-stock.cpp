class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=INT_MAX,mxpro=INT_MIN;
        int n=prices.size();
        for(int i=0;i<n;i++){
            mn=min(mn,prices[i]);
            mxpro=max(mxpro,prices[i]-mn);
        }
        //cout<<mxpro<<"";
        return mxpro;
    }
};