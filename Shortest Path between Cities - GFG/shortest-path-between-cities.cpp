//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    
    
    int shortestPath( int x, int y){ 
        // code here 
        int cnt=0;
        
        while(x!=y){
            cnt++;
            if(x>y){
                x=x/2;
            }else 
                y=y/2;
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<< ob.shortestPath(x,y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends