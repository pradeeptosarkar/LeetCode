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
    Node* copyRandomList(Node* head) 
    {
        unordered_map<Node*, Node*> mp;
        Node* temp=head;
        
        while(temp)
        {
            Node* t= new Node (temp->val);
            mp[temp] = t;
            temp=temp->next;
        }
        
        temp=head;
        
        while(temp)
        {
            Node* t = mp[temp];
            t->next = (temp->next==NULL) ? NULL : mp[temp->next];
            t->random = (temp->random==NULL) ? NULL : mp[temp->random];
            
            temp=temp->next;
        }
        
        return mp[head];
    }
};