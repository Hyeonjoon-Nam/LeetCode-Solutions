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
    int kthSmallest(TreeNode* root, int k) {
        // ================================
        // Approach 1: BFS + Sorting
        // - Time  Complexity: O(N log N)
        //   (Visiting all nodes takes O(N), Sorting takes O(N log N))
        // - Space Complexity: O(N)
        //   (Queue for BFS O(w) + vector for all values O(N))
        // - Pros: Simple logic
        // - Cons: Inefficient
        // ================================
        if (root == nullptr || k < 1) return -1;

        queue<TreeNode*> q;
        q.push(root);

        vector<int> v;
        
        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                TreeNode* curr = q.front();
                q.pop();
                v.push_back(curr->val);
                
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        sort(v.begin(), v.end());

        if (k > v.size()) return -1;
        return v[k - 1];

        // ================================
        // Approach 2: Recursive In-order traversal
        // - Time  Complexity: O(H + k)
        //   (H is height, visits only up to the k-th node)
        // - Space Complexity: O(H)
        //   (Recursion stack space)
        // - Pros: No sorting needed.
        // - Cons: Uses recursion stack.
        // ================================
        count = k;
        traverse(root);
        return result;
    }

    // Approach 2
private:
    int count = 0;
    int result = 0;

public:
    void traverse(TreeNode* node) {
        if (!node) return;

        traverse(node->left);

        count--;
        if (count == 0) {
            result = node->val;
            return;
        }

        if (count > 0) traverse(node->right);
    }
};