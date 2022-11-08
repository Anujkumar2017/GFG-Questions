class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        int n=s.size();
        
        for(int i=0;i<n;i++){
            if(st.size()>0){
                char ch=st.top();
                if(abs(ch-s[i])==32){
                    st.pop();
                    continue;
                }
            }
            st.push(s[i]);
        }
        
        string ans;
        while(st.size()>0){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};