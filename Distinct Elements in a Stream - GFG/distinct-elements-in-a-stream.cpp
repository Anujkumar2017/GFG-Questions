//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  public:
    vector<int> maxDistinctNum(int arr[], int n)
    {
        // Complete the function
        unordered_map<int,int> mp;
        vector<int> v;
        
        for(int i=0; i<n; i++){
            if(arr[i]>0)
                mp[arr[i]]++;
            else{
                int num=arr[i]*-1;
                if(mp.find(num)!=mp.end()){
                    mp[num]--;
                    if(mp[num]==0)
                        mp.erase(num);
                }
            }
            v.push_back(mp.size());
        }
        
        return v;
    }

};

//{ Driver Code Starts.

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        for(int i=0; i < n ; i++){
            cin >> a[i];
        }
        vector<int> v;
        Solution obj;
        v = obj.maxDistinctNum(a, n);
        for(auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends