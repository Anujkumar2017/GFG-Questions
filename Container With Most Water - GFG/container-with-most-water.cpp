//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long a[], int len)
{
    // Your code goes here
    long long  area=0;
    int s=0,e=len-1;
    long long maxarea=0;
    
    while(s<e){
        area= min(a[s],a[e])*(e-s);
        maxarea=max(maxarea,area);
        if(min(a[s],a[e])==a[s])
            s++;
        else
            e--;
    }
    return maxarea;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends