//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends
//Back-end complete function template in C++

class Solution{
public:
    //Function to calculate minimum number of operations.
    int minOperations(int *a, int n)
    { 
        int sum = 0, dif = 0; 

        //Creating a min heap using priority queue.
        priority_queue<int, vector<int>, greater<int> > pq;

        //Iterating over the array.
        for (int i = 0; i < n; i++) { 
            //If the top element of the priority queue is smaller than current element,
            //calculate the difference and add it to the sum.
            if (!pq.empty() && pq.top() < a[i]) { 
                dif = a[i] - pq.top(); 
                sum += dif; 
                pq.pop(); 
                pq.push(a[i]); 
            } 
            
            //Push the current element into the priority queue.
    
            pq.push(a[i]);
        
        } 

        //Returning the sum of differences.
        return sum; 
    } 
};


//{ Driver Code Starts.

int main() {
    
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int  a[n+1];
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        Solution ob;
        cout<<ob.minOperations(a,n)<<endl;
    }
    
	return 0;
}
// } Driver Code Ends