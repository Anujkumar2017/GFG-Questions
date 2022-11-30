//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{ 
public:
    void reorderList(Node* head) {
        // Your code here
        Node *fast ,*slow;
        
        fast=head;
        slow=head;
        
        if(head==NULL || head->next==NULL){
            return;
        }
        
        //Find mid elsement of the linked list
        while(fast!=NULL){
            if(fast->next==NULL){
                break;
            }
            fast=fast->next->next;
            slow=slow->next;
        }
        
        // cout<<slow->data<<"\n";
        
        //Reverse the linked list haeded by slow
        Node *current ,*prev,*next;
        prev=NULL;
        current=slow;
        next=NULL;
        
        while(current!=NULL){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        
        // cout<<prev->data<<" ";
        
        Node *ptr=head;
        while(ptr->next!=slow){
            ptr=ptr->next;
        }
        
        ptr->next=prev;
        
        Node *ptr1,*ptr2,*temp1,*temp2;
        ptr1=head;
        ptr2=prev;
        
        
        while(1){
            temp1=ptr1->next;
            temp2=ptr2->next;
            ptr1->next=ptr2;
            if(temp1==prev){
                break;
            }
            ptr2->next=temp1;
            ptr1=temp1;
            ptr2=temp2;
        }
    }
};

//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends