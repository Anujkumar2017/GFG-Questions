class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string ans;
        
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(!st.empty() && st.top()==ch){
                st.pop();
                continue;
            }
            st.push(ch);
        }
        
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        
        return ans;
    }
};