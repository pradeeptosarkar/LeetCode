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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int N=0;
    for (auto node=head; node!=nullptr; node = node->next) {
        N++;
    }
    const int partSize = N/k;
    const int numOfLargeParts = N%k; 
    vector<ListNode*> result(k, nullptr); // null parts are kept when k is bigger than N.
    ListNode* node = head;
    for (int i=0; i<k; i++) {
        result[i] = node; 
        // Find the last node of each part.
        for (int j=0; j < partSize - 1 + (i<numOfLargeParts ? 1 : 0); j++) { 
            if (node!=nullptr) {            
                node = node->next;
            }
        }       
        if (node!=nullptr) { // Split the last node of the part from the list.
            auto prev = node;
            node = node->next;
            prev->next = nullptr;
        }
    }
    return result;
    }
};