//{ Driver Code Starts
//

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


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* solve(int start, int end, int n, int &preIndex, int in[], int pre[]){
        if(start>end || preIndex>=n) return NULL;
        
        Node *node=new Node(pre[preIndex]);
        
        int inIndex;
        for(inIndex=start;inIndex<=end;inIndex++){
            if(in[inIndex]==pre[preIndex]){
                break;
            }        
        }
        preIndex++;
        
        node->left=solve(start,inIndex-1,n,preIndex,in,pre);
        node->right=solve(inIndex+1,end,n,preIndex,in,pre);
        
        return node;    
    }

    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int start=0,end=n-1;
        int preIndex=0;
        Node* root=solve(start,end,n,preIndex,in,pre);
        return root;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends