class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i=0,n=intervals.size();
        
        while(i<n && intervals[i][1]<newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }
        
        vector<int> mI=newInterval;
        while(i<n && intervals[i][0]<=newInterval[1]){
            mI[0]=min(intervals[i][0],mI[0]);
            mI[1]=max(intervals[i][1],mI[1]);
            i++;
        }
        res.push_back(mI);
        
        while(i<n){
            res.push_back(intervals[i]);
            i++;
        }
        
        return res;
    }
};