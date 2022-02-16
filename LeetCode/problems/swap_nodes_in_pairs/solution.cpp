/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
    }
};*/
class Solution {

public:

    ListNode* swapPairs(ListNode* head) {

        

        ListNode* ans = new ListNode();

        ListNode* ans_head = ans;

        

        int cnt = 0 ,isOdd = 0;

        ListNode* temp = head;

        ListNode* prev = NULL;

        

        while(temp != NULL){

           

            if(cnt == 2) cnt = 0;

            

            if(cnt == 0){

                prev = new ListNode(temp->val);

            }else{

              ListNode* t2 = new ListNode(temp->val);

              ans->next = t2;

              ans = ans->next;

              ans -> next = prev;

              ans  = ans->next;

            }

            temp = temp->next;

            cnt++;

            isOdd++;

        }

        

        if(isOdd%2 != 0) ans->next = prev;

     

        return ans_head->next;

    }

};