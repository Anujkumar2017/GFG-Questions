//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    bool isprime(string s){
        int val = stoi(s);
        for(int i=2; i*i <= val; i++){
            if(val%i == 0){return false;}
        }
        return true;
    }
    
    int shortestPath(int Num1,int Num2)
    {   
        // Complete this function using prime vector
        string a,b;
        a=to_string(Num1);
        b=to_string(Num2);
        
        map<string,bool> visited;
        queue<string> q;
        q.push(a);
        
        int ans=0;
        q.push(a);
        
        if(Num1==Num2) 
            return ans;
            
        visited[a]=true;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                string t=q.front();
                q.pop();
                
                if(t==b) 
                    return ans;
                
                for(int d=0;d<4;d++){
                    for(int c=0;c<10;c++){
                        if(c==0 && d==0){
                            continue;
                        }
                        string temp=t;
                        temp[d]=to_string(c)[0];
                        if(isprime(temp) && visited[temp]==false){
                            q.push(temp);
                            visited[temp]=true;
                        }
                    }
                }
            }
           ans++; 
        }
        return ans;
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends