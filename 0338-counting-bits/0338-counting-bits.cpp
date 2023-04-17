class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v;
        for(int i=0;i<=n;i++){
            int cnt=0;
            int temp=i;
            while(temp){
                cnt+=temp%2;
                temp/=2;
            }
            v.push_back(cnt);
        }
        return v;
    }
};