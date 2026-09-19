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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL) return head;
        

        ListNode* temp = head;
        int n = 0;
        while( temp != NULL ){
            temp = temp -> next;
            n++;
        }

        k = k % n;
        if(k == 0) return head;
        int cut = n-k-1;

        ListNode* cutoff = head;
        while( cut != 0){
            cutoff = cutoff -> next;
            cut--;
        }

        ListNode* newHead = cutoff -> next;
        cutoff -> next = NULL;

        ListNode* t1 = newHead;
        while(t1 != NULL && t1->next != NULL){
            t1 = t1 -> next;
        }

        t1 -> next = head;
        return newHead;
    }
};