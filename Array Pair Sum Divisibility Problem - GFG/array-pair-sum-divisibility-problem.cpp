//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]%k]++;
        }
        
        int ans=true;
        for(auto x:mp){
            int a=x.first,b=x.second;
            if(a==0 || (a==k/2 && k%2==0)){
                if(b%2!=0){
                    ans=false;
                }
            }else{
                if(mp.find(k-a)!=mp.end()){
                    if(mp.find(k-a)->second!=b){
                        ans=false;
                    }
                }else{ 
                    ans=false;
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends