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
        // ================================
        // Approach 1: Recursive DFS (Path Max Tracking)
        // - Time  Complexity: O(N)
        //   (Visits every node once)
        // - Space Complexity: O(h)
        //   (h is tree height; recursion stack)
        // - Pros: Naturally tracks path information using the call stack.
        // - Cons: Can hit stack overflow on extremly deep trees.
        // ================================
        // return 1 + good(root, root->val);


        // ================================
        // Approach 2: Recursive DFS (More concise)
        // - Time  Complexity: O(N)
        //   (Visits every node once)
        // - Space Complexity: O(h)
        //   (h is the tree height)
        // - Pros: More concise than approach 1
        // - Cons: 
        // ================================
        return dfs(root, root->val);
    }

    // For approach 1
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

    // For approach 2
    int dfs(TreeNode* node, int maxSoFar) {
        if (!node) return 0;

        int count = 0;

        if (node->val >= maxSoFar) {
            count = 1;
        }
        maxSoFar = max(maxSoFar, node->val);

        return count + dfs(node->left, maxSoFar) + dfs(node->right, maxSoFar);
    }
};