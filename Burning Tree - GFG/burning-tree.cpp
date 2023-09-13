//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    map<Node*,bool> visited;
    Node* targetNode=NULL;
    
    void BFS(Node* node, int &level, map<Node*,Node*> &parent){
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                Node* temp=q.front();
                q.pop();
                
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
            level++;
        }
        level--;
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
    
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        int sec=0;
        
        map<Node*,Node*> parent;          //{node,parent}
        parent[root]=NULL;
        
        traverse(root,target,parent);
        
        BFS(targetNode,sec,parent);
        
        return sec;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends