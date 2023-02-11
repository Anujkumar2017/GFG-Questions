//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:
   bool isprime(int n){
        if(n<=1){
            return false;
        }
        for(int i=2;i<=sqrt(n);++i){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }

    int min_near_prime(int n){
        if(isprime(n)==true){
            return n;
        }
        for(int i=1;;++i){
            if(isprime(n-i)==true) return n-i;
            if(isprime(n+i)==true) return n+i;
        }
        return -1;
    }
    Node *primeList(Node *head){
        for(Node *temp = head;temp!=NULL;temp=temp->next){
            // cout<<temp->val<<endl;
            temp->val = min_near_prime(temp->val);
        }
        return head;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends