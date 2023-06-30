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
    ListNode* head;
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        
        if(h1 == NULL)return h2;
        if(h2 == NULL)return h1;

        if(h1->val <= h2->val){
         head = h1;
         h1 = h1->next;
        }
        else{
         head = h2;
         h2 = h2->next;
        }

        ListNode* curr = head;

        while(h1 and h2){
            if(h1->val <= h2->val){
             
                curr->next = h1;
                h1 = h1->next;
            }
            else
            {   
                curr->next = h2;
                h2 = h2->next;
            }
            curr = curr->next;
        } 

        if(!h1)
        curr->next = h2;
        else
        curr->next = h1;       

        return head;
    }
};