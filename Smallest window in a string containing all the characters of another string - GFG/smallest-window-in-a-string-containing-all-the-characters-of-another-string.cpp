//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        string ans="";
        int n=s.size();
        vector<int>map1(26,0), map2(26,0);
        
        for(char ch:p){
            map2[ch-'a']++;
        }
        
        int mct=0;   // Match count
        int dcmt=p.size();  // Desired match count
        int i=-1,j=-1;
        
        while(true){
            bool f1=false;
            bool f2=false;
            
            
            // Acquire
            while(i<n-1 && mct<dcmt){
                i++;
                char ch=s[i];
                map1[ch-'a']++;
                if(map1[ch-'a']<=map2[ch-'a']){
                    mct++;
                }
                f1=true;
            }
            
            // Collect answers and release
            while(j<i && mct==dcmt){
                string pans= s.substr(j+1,i-j);
                if(ans.size()==0 || pans.size()<ans.size()){
                    ans=pans;
                }
                
                j++;
                char ch=s[j];
                map1[ch-'a']--;
    
                if(map1[ch-'a']<map2[ch-'a']){
                    mct--;
                }
                
                f2=true;
            }
            
            if(f1==false && f2==false)
                break;
        }
        
        if(ans=="")
            return "-1";
        
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
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends