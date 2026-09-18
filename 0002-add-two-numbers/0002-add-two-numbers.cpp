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
    

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        
        int sum = 0;
        int carry = 0;

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while( t1 != NULL || t2 != NULL ){
            int val1 = (t1 != NULL) ? t1 -> val : 0;
            int val2 = (t2 != NULL) ? t2 -> val : 0;
             sum = val1 + val2 + carry;
             int digit = sum % 10;
             carry = sum / 10;

             ListNode* newNode = new ListNode(digit);

             temp -> next = newNode;
             temp = temp -> next;

             if(t1 != NULL) t1 = t1 -> next;
             if(t2 != NULL) t2 = t2 -> next;
        }

        if(carry != 0){
            temp -> next = new ListNode(carry);
             
        }

        return dummy->next;
    }
};