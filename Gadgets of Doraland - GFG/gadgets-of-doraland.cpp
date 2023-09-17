//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function template in C++

class Solution{
    public:
    //Function to find the top k most frequent elements in the array.
    vector<int> TopK(vector<int>& array, int k)
    {
        int i,j=0; //initialize variables i and j for looping and counting
        int arr[10002]; //initialize array to store frequency of elements
        
        //initialize all elements of arr array as 0
        for(i=0;i<10002;i++)
            arr[i] = 0;
            
        //count the frequency of each element in the array
        for(i=0;i<array.size();i++)
            arr[array[i]]++;
        
        vector<int>res[100002]; //create a 2D vector to store elements based on their frequency
        
        //store elements in res vector based on their frequency
        for(i=0;i<10002;i++)
            {
                if(arr[i]!=0)
                    res[arr[i]].push_back(i);
            }
            
        vector<int>ans; //create a vector to store the final answer
        for(i=100001;i>=0;i--)
            {
                for(int p = res[i].size()-1;p>=0;p--)
                    {
                        //check if the number of elements in the ans vector is less than k,
                        //if yes, then add the element to ans vector
                        //if no, then break the loop
                        if(j!=k)
                            ans.push_back(res[i][p]);
                        else
                            break;
                        j++; //increment j to keep track of number of elements added to ans vector
                    }
            }
        return ans; //return the final answer vector
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k ;
        cin>>n;
        
        vector<int>array(n);
        
        for(int i=0; i<n; i++)
            cin>>array[i];
            
        cin>>k;
        
        Solution obj;
        vector<int> result = obj.TopK(array,k);
        
        for(int i=0; i<result.size();i++)
            cout<<result[i]<<" ";

        cout<<"\n";

    }
    return 0;
}
// } Driver Code Ends