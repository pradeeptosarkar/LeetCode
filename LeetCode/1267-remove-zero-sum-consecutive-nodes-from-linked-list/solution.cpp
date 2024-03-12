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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* front = new ListNode(0, head);
        ListNode* current = front;
        int prefixSum = 0;
        unordered_map<int, ListNode*> prefixSumToNode;
        
        while (current != nullptr) 
        {
            prefixSum += current->val;

            if (prefixSumToNode.find(prefixSum) != prefixSumToNode.end()) 
            {
                ListNode* prev = prefixSumToNode[prefixSum];
                current = prev->next;

                int p = prefixSum + current->val;
                
                while (p != prefixSum) 
                {
                    prefixSumToNode.erase(p);
                    current = current->next;
                    p += current->val;
                }

                prev->next = current->next;
            } 
            
            else 
            {
                prefixSumToNode[prefixSum] = current;
            }
            
            current = current->next;
        }
        return front->next;
    }
};
