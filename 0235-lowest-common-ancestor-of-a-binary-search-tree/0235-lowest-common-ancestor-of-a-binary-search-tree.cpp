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
        // ================================
        // Approach 1: Iterative BST traversal
        // - Time  Complexity: O(h)
        //   (h is the height of the tree.)
        // - Space Complexity: O(1)
        //   (Constant space used for pointers)
        // - Pros: Memory efficient.
        // - Cons: Only works for BST.
        // ================================
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


        // ================================
        // Approach 2: Recursive
        // - Time  Complexity: O(N)
        //   (Same as iterative, visits nodes along the path to LCA)
        // - Space Complexity: O(h)
        //   (Implicit stack space used by recursion, proportional to tree height)
        // - Pros: Concise
        // - Cons: Recursion overhead
        // ================================
        // if (!root || !p || !q) return nullptr;

        // int val = root->val;
        // int pVal = p->val;
        // int qVal = q->val;

        // if (pVal > val && qVal > val) {
        //     return lowestCommonAncestor(root->right, p, q);
        // } else if (pVal < val && qVal < val) {
        //     return lowestCommonAncestor(root->left, p, q);
        // } else {
        //     return root;
        // }
    }
};