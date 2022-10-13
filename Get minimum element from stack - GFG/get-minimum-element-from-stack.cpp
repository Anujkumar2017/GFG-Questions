//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    // we create another stack supporting stack ss such that it's top always have minimum of 
    // stack st;
    stack<int> st,ss;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
            if(!ss.empty())
                return ss.top();
            else
                return -1;
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           //Write your code here
            if(!st.empty()){
                int num=st.top();
                st.pop();
                
                // pop in stack ss when num is equal to ss.top
                // that is num is min element of the stack st
                if(!ss.empty() && num==ss.top() )
                    ss.pop();
                return num;
            }
            else
                return -1;
       }
       
       /*push element x into the stack*/
       void push(int x){

           //Write your code here
           st.push(x);
           
           //push in stack ss when ss is empty or x is less than equal to ss.top
           if(ss.empty() || x<=ss.top()){
               ss.push(x);
           }
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends