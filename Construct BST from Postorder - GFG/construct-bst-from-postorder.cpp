//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
	

}

int main ()
{   
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

	printInorder(root);
    printf("\n");
}
	return 0;
}

// } Driver Code Ends


/*struct Node
{
	int data;
	Node *left, *right;
};*/
Node* solve(int &idx, int min, int max, int post[]){
    if(idx<0 || post[idx]>max || post[idx]<min)
        return NULL;
    
    
    Node *node=new Node(post[idx--]);
    
    node->right=solve(idx,node->data,max,post);
    node->left=solve(idx,min,node->data,post);
    
    return node;
}

Node *constructTree (int post[], int size)
{
    //code here
    int idx=size-1;
    // cout<<"\n";
    return solve(idx,INT_MIN,INT_MAX,post);
}