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
    int maxDepth(TreeNode* root) {
        // ================================
        // Approach 1: Recursive DFS
        // - Time  Complexity: O(N)
        //   (Every node is processed once)
        // - Space Complexity: O(h)
        //   (h is the height of the tree)
        // - Pros: Extremly concise.
        // - Cons: Recursive overhead.
        // ================================
        // if (root == nullptr) return 0;
        // return 1 + max(maxDepth(root->left), maxDepth(root->right));

        // ================================
        // Approach 2: Iterative BFS
        // - Time  Complexity: O(N)
        //   (Every node is processed once)
        // - Space Complexity: O(w)
        //   (w is the maximum width of the tree)
        // - Pros: Avoids recursion stack overflow.
        // - Cons: Uses extra memory for the queue.
        // ================================
        if (root == nullptr) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            depth++;
        }
        return depth;
    }
};