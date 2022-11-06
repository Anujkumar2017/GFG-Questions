class Solution {
public:
    string orderlyQueue(string s, int k) {
        // return sorted string when k>1
        if(k>1){
            sort(s.begin(),s.end());
            return s;
        }
        
        //rotate first char and find lexicographically min string 
        string temp=s;
        for(int i=0;i<s.size();i++){
            temp=min(temp,s.substr(i)+s.substr(0,i));
        }
        return temp;
    }
};