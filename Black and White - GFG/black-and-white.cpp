//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int N, int M)
{
    // write code here
    long long mod=1e9+7,ans=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            long long cnt=N*M-1;
            if(i-2>=0 && j-1>=0) cnt--;
            if(i-2>=0 && j+1<M) cnt--;
            if(i+2<N && j-1>=0) cnt--;
            if(i+2<N && j+1<M) cnt--;
            if(j-2>=0 && i-1>=0) cnt--;
            if(j-2>=0 && i+1<N) cnt--;
            if(j+2<M && i-1>=0) cnt--;
            if(j+2<M && i+1<N) cnt--;
            
            ans=ans%mod+cnt%mod;
            ans=ans%mod;
        }
    }
    return ans;
}