/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* temp = head;
        while(temp != NULL){
            Node* next = temp -> next;
            Node* copy = new Node(temp -> val);
            temp -> next = copy;
            copy -> next = next;
            temp = next;
        }

        temp = head;
        while(temp != NULL && temp -> next != NULL){
            if(temp -> random != NULL) temp -> next -> random = temp -> random -> next;
            
            temp = temp -> next -> next;
        }

        
       Node* copyHead = head->next;
       temp = head;

        while (temp != NULL) {

            Node* copy = temp->next;
            Node* nextOriginal = copy->next;

            temp->next = nextOriginal;

            if (nextOriginal != NULL)
                copy->next = nextOriginal->next;
            else
                copy->next = NULL;

            temp = nextOriginal;
        }

        return copyHead;
    }
};