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

    ListNode* getKthNode(ListNode* head, int k){
        ListNode* temp = head;
        while(k != 1 && temp != NULL){
            temp = temp -> next;
            k--;
        }
        return temp;
    }

    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != 0){
            ListNode* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while(temp != NULL){
           ListNode* kthNode = getKthNode(temp, k);

           if(kthNode == NULL){
                if(prevLast != NULL) prevLast -> next = temp;
                break;
           }

           ListNode* nextNode = kthNode -> next;

           kthNode -> next = NULL;
           reverseList(temp);
           if(temp == head){
            head = kthNode;
           } 
           else{
            prevLast->next = kthNode;
            
           }
           prevLast = temp;
           temp = nextNode;

        }
        return head;
    }   
};