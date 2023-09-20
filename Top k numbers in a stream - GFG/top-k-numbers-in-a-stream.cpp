//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
struct cf{
    bool operator()(pair<int, int> &p1, pair<int, int> &p2)
    {
        if(p1.second==p2.second)
        {
            return p1.first<p2.first;
        }
        return p1.second>p2.second;
    }
};

class Solution
{
  public:
    vector<int> kTop(int a[], int n, int k)
    {
        //code here.
        unordered_map<int, int> m;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            m[a[i]]++;
            
            //min heap (with <max value, min freq> entries)
            priority_queue<pair<int, int>, vector<pair<int, int>>, cf> Q;
            for(auto it=m.begin(); it!=m.end();it++)
            {
                if(Q.size()<k)
                {
                    Q.push({it->first, it->second});
                }
                else if(Q.top().second<it->second || (Q.top().second==it->second && Q.top().first>it->first))
                {
                    Q.pop();
                    Q.push({it->first, it->second});
                }
            }
            
            //as the order of the elements popped out from priority_queue is reverse to what reqd
            stack<int> S;
            while(!Q.empty())
            {
                S.push(Q.top().first);
                Q.pop();
            }
            while(!S.empty())
            {
                ans.push_back(S.top());
                S.pop();
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	long long t;
	
	cin >> t;
	
	while(t--){
	    long long n;
	    long long k;
	    cin >> n;
	    cin >> k;
	    int a[n];
	    for(long long i = 0;i<n;i++){
	        cin >> a[i];
	    }
	        Solution ob;
	        vector<int> ans;
	        ans=ob.kTop(a,n,k);
	        for(int i=0;i<ans.size();i++)
	        {
	        cout<<ans[i];
	        cout<<" ";
	        }
	        cout<<'\n';
	    }
	return 0;
}

// } Driver Code Ends