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
    ListNode* reverse(ListNode* &head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            ListNode* f = curr->next;
            curr->next = prev;
            prev = curr;
            curr = f;
        }
        return prev;
   }
    bool isPalindrome(ListNode* head) {
       int l = 0,hl = 0;
       ListNode* temp = head;
       while(temp != NULL){
           l++;
           temp = temp->next;
       } 
       hl = l/2;
       ListNode* start = head;
       ListNode* end = head;
       while(hl--){
          end = end->next;
       }
      // cout<<end->next->val;
       end = reverse(end);
       while(end != NULL){
           if(start->val != end->val)
           return false;
           start = start->next;
           end = end->next;
       }
       return true;
    }
};
