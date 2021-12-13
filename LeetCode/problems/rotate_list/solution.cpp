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
        if(head == NULL) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = dummy;
        int length = 0;
        while(cur->next){
            cur = cur->next;
            length++;
        }
        if(k % length == 0) return head;
        int cnt = length - k % length;
        ListNode* back = dummy;
        while(cnt--){
            back = back->next;
        } 
        dummy->next = back->next;
        back->next = NULL;
        cur->next = head;
        return dummy->next;
    }
};