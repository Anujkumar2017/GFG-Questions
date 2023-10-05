//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

/*Function to count subset with even sum
* arr : array input
* N : size of array
*/
class Solution{
  public:
    int countSumSubsets(int arr[], int N){
        
        // Your code here
        int cnt=0;
        
        for(int i=0; i<(1<<N); i++){
            int sum=0;
            
            for (int j = 0; j < N; j++) {
                if (i & (1 << j))
                    sum+=arr[j];
            }
            
            if(sum%2==0 && sum!=0)
                cnt++;
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.

// Driver code to test columnWithMaxZeros function
int main() {
	
	int testcase;
	
	cin >> testcase;
	
	while(testcase--){
	    int N;
	    cin >> N;
	    
	    int arr[N];
	    
	    // Taking elements input into the matrix
	    for(int i = 0;i<N;i++){
	            cin >> arr[i];
	        }
	    Solution obj;
	    cout << obj.countSumSubsets(arr, N) << endl;
	}
	
	return 0;
}
// } Driver Code Ends