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

    void insertAtTail(ListNode* &head,ListNode* &tail,int val){
         ListNode* temp = new ListNode(val);
         if(head == NULL){
             head = temp;
             tail = temp;
             return;
         }
         else
         {
             tail->next = temp;
             tail = temp;
         }
    }
    ListNode* add(ListNode* first,ListNode* second){
        int carry = 0;
        ListNode* anshead = NULL;
        ListNode* anstail = NULL;

        while(first != NULL and second != NULL){
            int sum = carry + first->val + second->val;
            int digit = sum % 10;
            insertAtTail(anshead,anstail,digit);
            carry = sum/10;
            first = first->next;
            second = second->next;
        }

        while(first != NULL){
            int sum = carry + first->val;
            int digit = sum % 10;
            insertAtTail(anshead,anstail,digit);
            carry = sum/10;
            first = first->next;
        }
        while(second != NULL){
            int sum =  carry + second->val;
            int digit = sum % 10;
            insertAtTail(anshead,anstail,digit);
            carry = sum/10;
            second = second->next;
        }
        while(carry != 0){
            int sum = carry;
            int digit = sum%10;
            insertAtTail(anshead,anstail,digit);
            carry = sum/10;
        }
         
       return anshead;    
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
        ListNode* newHead = add(l1,l2);
        
        return newHead;
    }
};