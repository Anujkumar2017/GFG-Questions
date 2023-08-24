//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here
       bool neg=0;
       if(s1[0]=='-'){
           neg^=1;
           s1=s1.substr(1);
       }
       
       if(s2[0]=='-'){
           neg^=1;
           s2=s2.substr(1);
       }
       
       int n=s1.size();
       int m=s2.size();
       
       vector<int> v(n+m+1,0);
       reverse(s1.begin(),s1.end());
       reverse(s2.begin(),s2.end());
       
       for(int i=0;i<m;i++){
           int x=s2[i]-'0';
        //   cout<<x<<" ";
           int pos=i;
           for(int j=0;j<n;j++){
               int y=s1[j]-'0';
            //   cout<<y<<"\n";
               v[pos]+=x*y;
               if(v[pos]>9){
                   v[pos+1]+=v[pos]/10;
                   v[pos]=v[pos]%10;
               }
               pos++;
           }
       }
       
       string ans="";
       bool zero=true;
       
       for(int i=v.size()-1;i>=0;i--){
        //   cout<<ans<<" "<<v[i]<<" \n";
            if(v[i]!=0)
                zero=false;
            if(!zero)
                ans+=(v[i]+'0');
       }
       
       if(neg)
            ans='-'+ans;
            
        return ans;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends