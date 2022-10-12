class Solution {
public:
    int minIncrementForUnique(vector<int>& arr) {
        int n = arr.size();
        
        int moves = 0;
        
        // sort the array
        
        sort(arr.begin(), arr.end());
        
        for(int i = 1; i < n; i++)
        {
            // if curr no. is less than equal to previous no.
            
            if(arr[i] <= arr[i - 1])
            {
                moves += abs(arr[i] - arr[i-1])+1;
                
                arr[i] = arr[i - 1] + 1;
            }
        }
        
        return moves;
    }
};