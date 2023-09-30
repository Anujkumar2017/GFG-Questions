//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    bool isValid(int n){
        unordered_map<int,int> mp;
        while(n>0){
            int dig=n%10;
            mp[dig]++;
            if(mp[dig]>1){
                return false;
            }
            n/=10;
        }
        return true;
    }
    vector<int> uniqueNumbers(int L,int R)
    {
        // Write Your Code here
        vector<int> v;
        
        for(int i=L; i<=R; i++){
            if(isValid(i))
                v.push_back(i);
        }
        
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l,r ;
        cin >> l >> r;
		Solution ob;
		vector<int> numbers = ob.uniqueNumbers(l,r);
		
		for(int num : numbers){
		   cout<<num<<" ";
		}
		cout<<endl;
        
    }
    return 0;
}
// } Driver Code Ends