class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int> count;
        int ans=INT_MIN;
        for(int i=0,j=0;j<fruits.size();j++){
            count[fruits[j]]++;
            while(count.size()>2){
                if(--count[fruits[i]]==0)
                    count.erase(fruits[i]);
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};