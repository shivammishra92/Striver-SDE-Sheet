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
    int getlen(ListNode* &head){

        ListNode* temp = head;
        int l = 1;
        while(temp != NULL){
            l++;
            temp = temp->next;
        }

        return l;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int l = getlen(head);
        
        if(head == NULL)
        return NULL;
        
        if(k < l){
            
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;

        int count = 0;
        while(curr != NULL and count < k){

           forward = curr->next;
           curr->next = prev;
           prev = curr;
           curr = forward;
           count++; 
        }

        if(forward != NULL)
        head->next = reverseKGroup(forward,k);

        return prev;
    }
        
        return head;
    }
};