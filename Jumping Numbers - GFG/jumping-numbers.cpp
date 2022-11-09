//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long jumpingNums(long long X) {
        // code here
        queue<long long> q;
        vector<long long> v;
        
        for(long long i=1;i<=9 && i<=X;i++){
            q.push(i);
        }
        
        //BFS
        while(!q.empty()){
            long long num=q.front();
            q.pop();
            if(num<=X){
                v.push_back(num);        
                long long lastdigit=num%10;
                
                if(lastdigit==0){
                    q.push(num*10+lastdigit+1);
                }
                else if(lastdigit==9){
                    q.push(num*10+lastdigit-1);
                }
                else{
                    q.push(num*10+lastdigit-1);
                    q.push(num*10+lastdigit+1);
                }
            }
        }
        
        return v[v.size()-1];
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends