//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

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


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/

class Solution{
public:
    map<Node*,bool> visited;
    Node* targetNode=NULL;
    
    void BFS(Node* node, int k, int &sum, map<Node*,Node*> &parent){
        queue<Node*> q;
        q.push(node);

        int level=0;
        
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                Node* temp=q.front();
                q.pop();
                
                if(level<=k){
                    sum+=temp->data;
                    visited[temp]=true;
                    
                    if(temp->left!=NULL and visited[temp->left]!=true){
                        q.push(temp->left);
                    }
                    
                    if(temp->right!=NULL and visited[temp->right]!=true){
                        q.push(temp->right);
                    }
                    
                    Node *p=parent[temp];
        
                    if(p!=NULL and visited[p]!=true){
                        q.push(p);
                    }
                }
            }
            level++;
        }
        
    }
    
    void traverse(Node* node, int target, map<Node*,Node*> &parent){
        if(node==NULL) return;
        
        if(node->data==target){
            targetNode=node;
        }
        
        if(node->left) parent[node->left]=node;
        if(node->right) parent[node->right]=node;
    
        traverse(node->left,target,parent);
        traverse(node->right,target,parent);
    }
    
    int sum_at_distK(Node* root, int target, int k)
    {
        // code here
        int sum=0;
        
        map<Node*,Node*> parent;          //{node,parent}
        parent[root]=NULL;
        
        traverse(root,target,parent);
        
        if(targetNode==NULL)
            return 0;
    
        BFS(targetNode,k,sum,parent);
        
        return sum;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int target,k;
        cin>> target >> k;
        getchar();
        
        Solution ob;
        cout<< ob.sum_at_distK(root,target,k) << endl;
    }
	return 0;
}


// } Driver Code Ends