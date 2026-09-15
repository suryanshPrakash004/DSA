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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            temp = temp -> next;
            count++;
        }
        int k = count - n;

        if(k == 0){
            head = head -> next;
            return head;
        }
        
        
        temp = head;
        ListNode* prev = NULL;
        while(k != 0){
            prev = temp;
            temp = temp -> next;
            k--;
        }

        if(temp != NULL){
             prev -> next = temp -> next;
             temp -> next = NULL;
        }
       

        return head;
    }
};