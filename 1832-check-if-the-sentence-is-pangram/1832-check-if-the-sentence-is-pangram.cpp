class Solution {
public:
    bool checkIfPangram(string sentence) {
        int n=sentence.size();
        map<char,bool> mp;
        
        for(int i=0;i<26;i++){
            mp['a'+i]=false;
        }
        
        for(int i=0;i<n;i++){
            mp[sentence[i]]=true;
        }
        
        for(auto x:mp){
            if(x.second==false)
                return false;
        }
        
        return true;
    }
};