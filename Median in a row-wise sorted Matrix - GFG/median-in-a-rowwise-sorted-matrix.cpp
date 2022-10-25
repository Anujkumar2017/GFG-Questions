//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &mat, int R, int C){
        // code here 
        int a[R*C],k=0;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                a[k]=mat[i][j];
                k++;
            }
        }
        sort(a,a+R*C);
        if((R*C)%2==0)
            return (a[(R*C)/2]+a[(R*C)/2-1])/2;
        return a[(R*C)/2];
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends