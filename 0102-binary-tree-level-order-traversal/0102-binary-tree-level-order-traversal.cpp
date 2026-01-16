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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // ================================
        // Approach 1: Iterative FGS
        // - Time  Complexity: O(N)
        //   (Every node in the tree is visited exactly once.)
        // - Space Complexity: O(w)
        //   (w is the maximum width of the tree.)
        // - Pros: Naturally processes nodes level by level.
        // - Cons: Requires extra memory for the queue.
        // ================================
        if (root == nullptr) return {};

        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                currentLevel.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(currentLevel);
        }
        return result;
    }
};