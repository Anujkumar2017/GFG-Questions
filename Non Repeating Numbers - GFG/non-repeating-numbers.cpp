//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int xsum=0;
        int n=nums.size();
        vector<int> v;
        
        for(int i=0;i<n;i++){
            xsum=xsum xor nums[i];
        }
        
        // right most set bit
        int bit= xsum&~(xsum-1);
        int x=0,y=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]&bit){
                x=x^nums[i];
            }else{
                y=y^nums[i];
            }
        }
    
        v.push_back(x);
        v.push_back(y);
        sort(v.begin(),v.end());
        return v;
    }
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends