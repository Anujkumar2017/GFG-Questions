//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution
{
    public:
    string rearrangeString(string str)
    {
        //code here
        map<char,int> mp;
        string ans="";
        
        for(auto ch:str){
            mp[ch]++;
        }
        
        priority_queue<pair<int,char>> pq;
        
        for(auto x:mp){
            pq.push({x.second,x.first});
        }
        
        while(pq.size()>1){
            auto p1=pq.top();
            pq.pop();
            p1.first--;
            ans+=p1.second;
            
            auto p2=pq.top();
            pq.pop();
            p2.first--;
            ans+=p2.second;
            
            if(p1.first) pq.push({p1.first,p1.second});
            if(p2.first) pq.push({p2.first,p2.second});
        }
        
        if(pq.size()){
            if(pq.top().first==1)
                ans+=pq.top().second;
            else 
                return "-1";
        }
        
        return ans;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}
// } Driver Code Ends