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
    bool isValidBST(TreeNode* root) {
        // ================================
        // Approach 1: Recursive DFS
        // - Time  Complexity: O(N)
        //   (Visits each node once)
        // - Space Complexity: O(h)
        //   (h is the height of tree)
        // - Pros: Intuitive.
        // - Cons: Recursion overhead
        // ================================
        // if (root == nullptr) return true;
        // return dfs(root, LONG_MIN, LONG_MAX);

        // ================================
        // Approach 2: In-order Traversal
        // - Time  Complexity: O(N)
        //   (Visits each node once)
        // - Space Complexity: O(h)
        //   (h is the height of tree)
        // - Pros: 
        // - Cons: Need to track the previous node
        // ================================
        return inorder(root);
    }

    // Approach 1
    bool dfs(TreeNode* node, long long minVal, long long maxVal) {
        if (node == nullptr) return true;

        if (node->val <= minVal || node->val >= maxVal) return false;

        return dfs(node->left, minVal, node->val) && dfs(node->right, node->val, maxVal);
    }

    // Approach 2
    TreeNode* prev = nullptr;
    bool inorder(TreeNode* node) {
        if (node == nullptr) return true;

        if (!inorder(node->left)) return false;
        if (prev != nullptr && node->val <= prev->val) return false;

        prev = node;
        return inorder(node->right);
    }
};