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
    int maxPathSum(TreeNode* root) {
        // ================================
        // Approach 1: Post-order DFS (Bottom-up)
        // - Time  Complexity: O(N)
        //   (Each node is visited once)
        // - Space Complexity: O(H)
        //   (H is the height of the tree for the call stack)
        // - Pros: Finds global maximum while traversing the tree only once.
        // - Cons: Logic for return vs. global update can be tricky initially.
        // ================================
        maxSum = INT_MIN;
        pathSum(root);
        return maxSum;
    }

public:
    int maxSum;

    int pathSum(TreeNode* node) {
        if (!node) return 0;
        int leftSum = pathSum(node->left);
        int rightSum = pathSum(node->right);
        maxSum = max(maxSum, node->val + max(0, leftSum) + max(0, rightSum));

        return node->val + max(0, max(leftSum, rightSum));
    }
};