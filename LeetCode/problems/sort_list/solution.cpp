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
    ListNode* sortList(ListNode* head) {
        
    }
};*/

class Solution {

public:

    ListNode* sortList(ListNode* head) {

        vector<int> ans;

        ListNode* tmp=head;

        while(tmp!=NULL){

            ans.push_back(tmp->val);

            tmp=tmp->next;

        }

        sort(ans.begin(), ans.end());

        ListNode * a=new ListNode(0);

        ListNode * h=a;

        for(auto it:ans){

            a->next=new ListNode(0);

            a=a->next;

            a->val+=it;

        }

        return h->next;

    }

};