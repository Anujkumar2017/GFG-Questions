//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};





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
   Node* root = new Node(stoi(ip[0]));

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
           currNode->left = new Node(stoi(currVal));

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
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



// } Driver Code Ends
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
class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    void convertIntoLL(Node* root ,Node *&head){
        if(root==NULL) return;
        
        convertIntoLL(root->right,head);
        root->right=head;
        head=root;
        convertIntoLL(root->left,head);
    }
    
    Node *mergeLL(Node* head1, Node* head2){
        Node *head=NULL;
        Node *tail=NULL;
        
        while(head1!=NULL && head2!=NULL){
            if(head1->data<head2->data){
                if(head==NULL){
                    head=head1;
                    tail=head1;
                    head1=head1->right;
                }else{
                    tail->right=head1;
                    tail=head1;
                    head1=head1->right;
                }
            }else{
                if(head==NULL){
                    head=head2;
                    tail=head2;
                    head2=head2->right;
                }else{
                    tail->right=head2;
                    tail=head2;
                    head2=head2->right;
                }
            }
        }
        
        while(head1!=NULL){
            tail->right=head1;
            tail=head1;
            head1=head1->right;
        }
        
        while(head2!=NULL){
            tail->right=head2;
            tail=head2;
            head2=head2->right;
        }
        
        return head;
    }
    
    int countNodes(Node *head){
        int cnt=0;
        Node *temp=head;
        
        while(temp!=NULL){
            cnt++;
            temp=temp->right;
        }
        
        return cnt;
    }   

    Node *sortedLLToBST(Node *&head, int n){
        if(n<=0 || head==NULL) return NULL;
        
        // cout<<head->data<<" "<<n<<"\n";
        Node* left=sortedLLToBST(head,n/2);
        
        Node* root=new Node(head->data);
        
        root->left=left;
        
        head=head->right;
        root->right=sortedLLToBST(head,n-n/2-1);
        
        return root;
    }
    
    void inorder(Node *root, vector<int> &v){
        if(root==NULL) return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    
    vector<int> merge(Node *root1, Node *root2)
    {
        //Your code here
        Node *head1=NULL,*head2=NULL;
        convertIntoLL(root1,head1);
        // cout<<head1->data<<"\n";
        
        // Node *temp=head1;
        // while(temp!=NULL){
        //     cout<<temp->data<<" ";
        //     temp=temp->right;
        // }
        // cout<<"\n";
        
        convertIntoLL(root2,head2);
        
        // temp=head2;
        // while(temp!=NULL){
        //     cout<<temp->data<<" ";
        //     temp=temp->right;
        // }
        
        // cout<<"\n";
        
        Node *head=mergeLL(head1,head2);
        
        int n=countNodes(head);
        // cout<<n<<"\n";
        Node *mergedBST=sortedLLToBST(head,n);
        
        vector<int> ans;
        inorder(mergedBST,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends