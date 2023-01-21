//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int tempa=a,seta=0;
        while(tempa){
            if(tempa&1)
                seta++;
            tempa=tempa>>1;
        }
        
        int tempb=b,setb=0;
        while(tempb){
            if(tempb&1)
                setb++;
            tempb=tempb>>1;
        }
        
        if(seta==setb){
            return a;
        }else if(seta>setb){
            int ans=0;
            int rem=setb;
            for(int i=31;i>=0;i--){
                if(a&(1<<i)){
                    ans|=(1<<i);
                    rem--;
                } 
                if(rem==0)
                    return ans;
            }
        }else{
            int rem=setb-seta;
            int ans=a;
            for(int i=0;i<=31;i++){
                if((a&(1<<i))==0){
                    ans|=(1<<i);
                    rem--;
                } 
                if(rem==0) return ans;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends