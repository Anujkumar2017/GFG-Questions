//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      // code here
      int maxAns=INT_MIN, maxCell=-1;
      vector<int> max(N,0);
      
      for(int i=0;i<N;i++){
          if(Edge[i]!=-1){
              max[Edge[i]]+=i;
          }
      }
      
      for(int i=0;i<N;i++){
          if(maxAns<=max[i]){
              maxAns=max[i];
              maxCell=i;
          }
      }
      
      return maxCell;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends