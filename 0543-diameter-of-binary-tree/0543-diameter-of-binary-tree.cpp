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
private:
    int diameter = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return diameter - 1;
    }

    int depth(TreeNode* root) {
        if (root == nullptr) return 0;
        int l_depth = depth(root->left);
        int r_depth = depth(root->right);
        diameter = max(diameter, (1 + l_depth + r_depth));
        return 1 + max(l_depth, r_depth);
    }
};