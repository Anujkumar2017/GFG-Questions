/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        
        // Finding mid element slow pointer give mid element 
        while(fast!=NULL){
            fast=fast->next;
            if(fast==NULL){
                break;
            }else
                fast=fast->next;
            slow=slow->next;
        }
        
        // Deleting the slow pointer's node 
        cout<<slow->val<<"\n";      // value of mid element
        if(slow->next!=NULL){
            slow->val=slow->next->val;
            slow->next=slow->next->next;
        }
        else{
        // This is case when mid is last element. It occurs when linked list size is 2 & 1.
            if(head->next==slow)        //  when size is 2
                 head->next=NULL;
            else 
                head=NULL;
        }
        return head;
    }
};