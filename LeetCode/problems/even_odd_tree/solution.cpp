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
class Solution {
        public: bool isEvenOddTree(TreeNode * root) {
                queue < TreeNode * > q;
                q.push(root);
                q.push(NULL);
                int lvl = 0;
                int mini = INT_MAX, maxi = INT_MIN;
                while (!q.empty()) {
                        TreeNode * temp = q.front();
                        q.pop();
                        if (temp == NULL) {
                                if (!q.empty()) {
                                        q.push(NULL);
                                        lvl++;
                                }
                        } else {
                                if (temp -> left) q.push(temp -> left);
                                if (temp -> right) q.push(temp -> right);

                                if (lvl & 1) {
                                        maxi = INT_MIN;
                                        if (temp -> val % 2 != 0 || temp -> val >= mini) return false;
                                        mini = temp -> val;
                                } else {
                                        mini = INT_MAX;
                                        if (temp -> val % 2 == 0 || temp -> val <= maxi) return false;
                                        maxi = temp -> val;
                                }
                        }
                }
                return true;
        }
};