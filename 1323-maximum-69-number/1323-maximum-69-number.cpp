class Solution {
public:
    int maximum69Number (int num) {
        vector<int> digit;
        int n= num;
        while(n>0){
            digit.push_back(n%10);
            n/=10;
        }
        reverse(digit.begin(),digit.end());
        for(int i=0;i<digit.size();i++){
            if(digit[i]!=9){
                digit[i]=9;
                break;
            }
        }
        int n1=0;
        for(int s:digit){
            n1=n1*10+s;
        }
        return n1;  
    }
};