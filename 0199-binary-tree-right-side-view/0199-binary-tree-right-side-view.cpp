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
    vector<int> rightSideView(TreeNode* root) {
        // ================================
        // Approach 1: Iterative BFS (Level Order)
        // - Time  Complexity: O(N)
        //   (Visits every node once)
        // - Space Complexity: O(w)
        //   (w is max width; queue stores one level at a time)
        // - Pros: Intuitive
        // - Cons: Requires extra memeory for the queue.
        // ================================
        // if (root == nullptr) return {};

        // queue<TreeNode*> q;
        // q.push(root);
        // vector<int> res;

        // while (!q.empty()) {
        //     int levelSize = q.size();
        //     TreeNode* curr;

        //     for (int i = 0; i < levelSize; i++) {
        //         curr = q.front();
        //         q.pop();

        //         if (curr->left) q.push(curr->left);
        //         if (curr->right) q.push(curr->right);
        //     }
        //     res.push_back(curr->val);
        // }
        // return res;

        // ================================
        // Approach 2: Recursive DFS
        // - Time  Complexity: O(N)
        //   (Every node is visite once)
        // - Space Complexity: O(h)
        //   (h is the heigh of the tree)
        // - Pros: Very concise
        // - Cons: 
        // ================================
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }

    void dfs(TreeNode* node, int depth, vector<int>& res) {
        if (!node) return;

        if (res.size() == depth) {
            res.push_back(node->val);
        }

        dfs(node->right, depth + 1, res);
        dfs(node->left, depth + 1, res);
    }
};