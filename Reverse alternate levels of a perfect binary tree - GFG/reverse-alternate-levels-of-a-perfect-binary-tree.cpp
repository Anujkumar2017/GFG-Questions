//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

void reverseAlternate(struct Node *root);
void inorder(Node * node)
{
    if(node==NULL)
        return;
    
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        reverseAlternate(root);
        inorder(root);
        cout<<endl;
    }
    return 1;
}
// } Driver Code Ends


/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

void reverseAlternate(Node *root)
{
    //Your code here
    map<int,vector<int>> mp;
    queue<Node*> q;
	q.push(root);
	int level=1;
	while(!q.empty()){
	    int n=q.size();
	    vector<int> v;
	    for(int i=0;i<n;i++){
	        Node *temp=q.front();
	        q.pop();
	        v.push_back(temp->data);
	        if(temp->left) q.push(temp->left);
	        if(temp->right) q.push(temp->right);
	    }
	    
	    if(level%2==0){ 
	        reverse(v.begin(),v.end());
	        mp[level]=v;
	    }
	    
	    level++;
    }
    
    // for(auto x:mp){
    //     cout<<x.first<<" : ";
    //     for(auto y:x.second) cout<<y<<" ";
    //     cout<<"\n";
    // }
    
    q.push(root);
	level=1;
	while(!q.empty()){
	    int n=q.size(),idx=0;
	    vector<int> v;
	    if(level%2==0) v=mp[level];
	    for(int i=0;i<n;i++){
	        Node *temp=q.front();
	        if(level%2==0) temp->data=v[idx++];
	        q.pop();
	        if(temp->left) q.push(temp->left);
	        if(temp->right) q.push(temp->right);
	    }
	    level++;
    }
}