//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int arr[], int l, int r, int key){
        // l: The starting index
        // r: The ending index, you have to search the key in this range
        
        //complete the function here
        
        int min=0,mid,n=r+1;
        
        //find index of minimum number i.e number of rotation
        while(l<=r){
            mid=l+(r-l)/2;
            //cout<<l<<" "<<r<<" "<<mid<<"\n";
            if(arr[l]<arr[r]){
                min=l;
                break;
            }
            if(arr[(mid+1)%n]>arr[mid] && arr[mid]<arr[(mid-1+n)%n]){
                min=mid;
                break;
            }
            else if(arr[l]>arr[mid]){
                r=mid-1;
            }else if(arr[r]<arr[mid]){
                l=mid+1;
            }
        }
        
    
        // Apply BS for 0 to min-1
        int res1=-1;
        l=0;
        r=min-1;
        while(l<=r){
            mid=l+(r-l)/2;
            //cout<<l<<" "<<r<<" "<<mid<<"\n";
            if(arr[mid]==key){
                res1=mid;
                break;
            }
            else if(arr[mid]<key){
                l=mid+1;
            }else
                r=mid-1;
        }
        
        // Apply BS for min to n-1
        int res2=-1;
        l=min;
        r=n-1;
        while(l<=r){
            mid=l+(r-l)/2;
            //cout<<l<<" "<<r<<" "<<mid<<"\n";
            if(arr[mid]==key){
                res2=mid;
                break;
            }
            else if(arr[mid]<key){
                l=mid+1;
            }else
                r=mid-1;
        }
        
        if(res1>-1 || res2>-1)
            return max(res1,res2);
        else 
            return -1;
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends