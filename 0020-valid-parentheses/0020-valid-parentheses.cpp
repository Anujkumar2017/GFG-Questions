class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(st.empty() || s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }else{
                char ch=st.top();
                if((ch=='(' && s[i]==')') || (ch=='{' && s[i]=='}') || (ch=='[' &&       s[i]==']')){
                    st.pop();
                }else
                    return false;
            }
            
        }
        if(st.size()>0)
            return false;
        else 
            return true;
    }
};