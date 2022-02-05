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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
    ListNode* head;
    unordered_map<int64_t, ListNode*> prev_pointers;
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        this->head = head;
        
        // Build KMP automaton.
        auto current_pointer = head->next;
        ListNode* current_prev = head;
        if (current_pointer != nullptr) {
            prev_pointers[(int64_t)(current_pointer)] = current_prev;
        
            while (current_pointer->next != nullptr) {
                while (current_prev != head && current_prev->val != current_pointer->val)
                    current_prev = prev_pointers[(int64_t)(current_prev)];
                current_prev = (current_prev->val == current_pointer->val) ? current_prev->next : current_prev;
                prev_pointers[(int64_t)(current_pointer->next)] = current_prev;
                current_pointer = current_pointer->next;
            }
        }
        
        // Search using automaton on tree.
        return search(head, root);
    }
    
    bool search(ListNode* list_node, TreeNode* tree_node) 
    {
        if (list_node == nullptr)
            return true;
        if (tree_node == nullptr)
            return false;
        
        bool found = false;
        while (list_node != head && list_node->val != tree_node->val)
            list_node = prev_pointers[(int64_t)(list_node)];
        list_node = (list_node->val == tree_node->val) ? list_node->next : list_node;
        found |= (search(list_node, tree_node->left));
        found |= (search(list_node, tree_node->right));

        return found;
    }
};