class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int flips=0, countone=0;
        for(auto c:s){
            if(c=='1') 
                countone++;
            else 
                flips++;
            flips=min(flips, countone);
        }
        return flips;
    }
};