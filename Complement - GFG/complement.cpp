//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findRange(string str, int n) {
        // code here
        int left=0,right=-1,l=0,
        lmax=0,glmax=0;
        
        for(int i=0;i<n;i++){
            int num=str[i]=='0'? 1 : -1;
            if(lmax<0){
                if(num==1){
                    l=i;
                    lmax=1;
                }
            }else
                lmax+=num;
            if(glmax<lmax){
                glmax=lmax;
                left=l;
                right=i;
            }
        }
        if(right==-1)
            return {right};
        return {left+1,right+1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        } else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends