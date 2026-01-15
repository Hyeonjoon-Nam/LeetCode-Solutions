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
    TreeNode* invertTree(TreeNode* root) {
        // ================================
        // Approach 1: Recursive DFS
        // - Time  Complexity: O(N)
        //   (All nodes visited once)
        // - Space Complexity: O(h)
        //   (h is the height of the tree)
        // - Pros: Simple.
        // - Cons: Risks stack overflow if the tree is extremely deep.
        // ================================
        // invert(root);
        // return root;

        // ================================
        // Approach 2: Iterative BFS
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        if (root == nullptr) return nullptr;
        
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            swap(curr->left, curr->right);

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        return root;
    }

    void invert(TreeNode* node) {
        if (node == nullptr) return;

        invert(node->left);
        invert(node->right);
        
        swap(node->left, node->right);

        return;
    }
};