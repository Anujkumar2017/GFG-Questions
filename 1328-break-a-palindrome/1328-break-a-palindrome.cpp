class Solution {
public:
    string breakPalindrome(string palindrome) {
        // int n=76;
        // char ch=n;
        // n=ch+1;
        // cout<<ch<<" "<<n<<"\n";
        int sz=palindrome.size();
        if(sz==1){
            return "";
        }else{
            int i,change=0;
            string s="";
            for(i=0;i<sz;i++){
                if(palindrome[i]!='a' && change==0){
                    if(i!=sz/2){
                        s=s+'a';
                        change=1;
                    }else
                        s+=palindrome[i];
                }
                else{
                    if(change!=1 && i==sz-1){
                        s=s+'b';
                    }else 
                        s+=palindrome[i];
                }
            }
            return s;
        }
    }
};