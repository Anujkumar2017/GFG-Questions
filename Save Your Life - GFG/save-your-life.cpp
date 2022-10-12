//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    // use kadene's algorithm for problem
      string maxSum(string w,char x[], int b[],int n){
          // code here
          int sum=0,mx=INT_MIN,l=0,r=0,mxl,mxr;
          map<int,int> mp;
          
          for(int i=0;i<n;i++){
                mp[x[i]]=b[i];                    
          }
          //check all redefined asccii value for every element in string is negative   
          bool allnegative=true;
          
          for(int i=0;i<w.size();i++){
              if(mp[w[i]]>=0){
                  allnegative=false;
              }
          }
          
          if(allnegative==true){
            int ans=0;
            for(int i=0;i<n;i++){
                if(b[ans]<b[i])
                    ans=i;
            }
            char ch =x[ans];
            string s;
            s=ch;
            //cout<<ch<<" ";
            return s;
          }else{
              
            //apply kadene algorithm here
            for(int i=0;i<w.size();i++){
              if(sum<0){
                  sum=0;
                  l=i;
              }
              sum+=mp[w[i]];
              // if element's ASCII in not redefined
              if(mp[w[i]]==0)
                sum+=(int)w[i];
              
              if(sum>mx){
                  mx=sum;
                  r=i;
                  //keep the l and r for maximum sum 
                  mxl=l,mxr=r;
              }
          }
          return w.substr(mxl,mxr-mxl+1);    
        }
          
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends