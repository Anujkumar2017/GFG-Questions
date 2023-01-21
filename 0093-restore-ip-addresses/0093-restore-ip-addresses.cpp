class Solution {
public:
    void solve(string s,int start, int step, string ip, vector<string> & ans){
        if(start==s.size() && step==4){
            ip.erase(ip.end()-1);
            ans.push_back(ip);
            return;
        }
        
        if(s.size()-start>(4-step)*3)
             return;
        if(s.size()-start<(4-step))
             return;
        
        int num=0;
        for(int i=start;i<start+3;i++){
            num=num*10+(s[i]-'0');
            if(num<=255){
                ip+=s[i];
                solve(s,i+1,step+1,ip+'.',ans);
            }
            if(num==0) break;
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string ip;
        solve(s,0,0,ip,ans);
        return ans;
    }
};