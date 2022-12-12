class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
            return 1;
        else if(n==2)
            return 2;
       
        int one=1;
        int two=2;
        int ways=0;
        
        for(int i=3;i<=n;i++){
            ways=one+two;
            one=two;
            two=ways;
        }
        
        return ways;
    }
};