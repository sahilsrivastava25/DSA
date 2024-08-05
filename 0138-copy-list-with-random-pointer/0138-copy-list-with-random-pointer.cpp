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
        Node* temp = head;

        while(temp){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }

        temp = head;
        while(temp){
           Node* newNode = temp->next; 
           if(temp->random) newNode->random = temp->random->next;
           else newNode->random = NULL;

           temp = temp->next->next;
        }

        temp = head;
        Node* dNode = new Node(-1);
        Node* res = dNode;
        
        while(temp){
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }

        return dNode->next;
    }
};