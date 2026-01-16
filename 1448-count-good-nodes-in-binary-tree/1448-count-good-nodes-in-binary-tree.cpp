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
public:
    int goodNodes(TreeNode* root) {
        return 1 + good(root, root->val);
    }

    int good(TreeNode* root, int m) {
        if (root == nullptr) return 0;
        int count = 0;

        if (root->left) {
            if (root->left->val >= m) {
                count++;
            }
            count += good(root->left, max(m, root->left->val));
        }
        if (root->right) {
            if (root->right->val >= m) {
                count++;
            }
            count += good(root->right, max(m, root->right->val));
        }
        return count;
    }
};