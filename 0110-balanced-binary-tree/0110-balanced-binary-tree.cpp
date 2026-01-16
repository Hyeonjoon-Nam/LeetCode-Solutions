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
        // ================================
        // Approach 1: Top-down DFS with global flag
        // - Time  Complexity: O(N)
        //   (Visits all nodes regardless of balance status)
        // - Space Complexity: O(h)
        //   (Recursive call stack space)
        // - Pros: Simple and intuitive logic.
        // - Cons: Inefficient for large trees because it lacks an early exit mechanism.
        // ================================
        // depth(root);
        // return ans;

        // ================================
        // Approach 2: Bottom-up DFS (+ Early Exit)
        // - Time  Complexity: O(N)
        //   (In the best case of early failure, it's faster than O(N))
        // - Space Complexity: O(h)
        //   (Balanced tree: O(log N), Skewed tree: O(N))
        // - Pros: Optimal performance.
        // - Cons: Error propagation logic (-1) needs to be handled at each step.
        // ================================
        return checkHeight(root) != -1;
    }

    // From approach 1
    int depth(TreeNode* root) {
        if (root == nullptr) return 0;

        int l = root->left == nullptr ? 0 : depth(root->left);
        int r = root->right == nullptr ? 0 : depth(root->right);

        if (abs(l - r) > 1) ans = false;
        return 1 + max(l, r);
    }

    // From approach 2
    int checkHeight(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = checkHeight(root->left);
        if (left == -1) return -1;

        int right = checkHeight(root->right);
        if (right == -1) return -1;

        if (abs(left - right) > 1) return -1;

        return 1 + max(left, right);
    }
};