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
    bool ans = true;
    bool isBalanced(TreeNode* root) {
        depth(root);
        return ans;
    }

    int depth(TreeNode* root) {
        if (root == nullptr) return 0;

        int l = root->left == nullptr ? 0 : depth(root->left);
        int r = root->right == nullptr ? 0 : depth(root->right);

        if (abs(l - r) > 1) ans = false;
        return 1 + max(l, r);
    }
};