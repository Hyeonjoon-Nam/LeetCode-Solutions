/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return nullptr;

        int pVal = p->val;
        int qVal = q->val;

        while (root != nullptr) {
            int val = root->val;
            if (val < pVal && val < qVal) {
                root = root->right;
            } else if (val > pVal && val >qVal) {
                root = root->left;
            } else {
                return root;
            }
        }
        return nullptr;
    }
};