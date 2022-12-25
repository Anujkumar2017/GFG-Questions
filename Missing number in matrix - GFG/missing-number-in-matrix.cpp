//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    long long int MissingNo(vector<vector<int> >& a) {
        // Code here
        int n=a.size();
        int x=-1,y=-1;
        vector<long long int> rowSum(n,0),colSum(n,0);
        long long int leftDia=0,rightDia=0;
        
        for(int i=0;i<n;i++){
            leftDia+=a[i][i];
            rightDia+=a[i][n-i-1];
                
            for(int j=0;j<n;j++){
               if(a[i][j]==0){ 
                x=i;
                y=j;
               }
               rowSum[i]+=a[i][j];
               colSum[j]+=a[i][j]; 
            }
        }
        
        long long int rowSumAct = x==0 ? rowSum[x+1]: rowSum[x-1];
        long long int colSumAct = y==0 ? colSum[y+1]: colSum[y-1];
        long long int diff = rowSumAct - rowSum[x];
        
        if(diff<=0 ||  diff!=colSumAct-colSum[y]){
            return -1;
        }
        
        if(x==y){
            leftDia+=diff;
        }
        
        if(x==n-y-1){
            rightDia+=diff;
        }
        
        if(rightDia!=leftDia){
            return -1;
        }
        
        rowSum[x]+=diff;
        colSum[y]+=diff;
        
        for(int i=0;i<n;i++){
            if(rowSum[i]!=leftDia || colSum[i]!=rightDia){
                return -1;
            }
        }
        return diff;
     }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		long long int ans = ob.MissingNo(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends