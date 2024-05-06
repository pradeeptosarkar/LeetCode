class Solution {
public:
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0); 
        ListNode* current = ans;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry; 

            if (l1 != nullptr) {
                sum += l1->val; 
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val; 
                l2 = l2->next;
            }

            carry = sum / 10; 
            current->next = new ListNode(sum % 10); 
            current = current->next; 
        }

        return ans->next; 
    }
};
