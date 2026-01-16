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
        //   ()
        // - Space Complexity: O(h)
        //   ()
        // - Pros: Extremly concise.
        // - Cons: Recursive overhead.
        // ================================
        // if (root == nullptr) return 0;
        // return 1 + max(maxDepth(root->left), maxDepth(root->right));

        // ================================
        // Approach 2: Iterative BFS
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        if (root == nullptr) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left) q.push(curr->left);
                if (curr->left) q.push(curr->left);
            }
            depth++;
        }
        return depth;
    }
};