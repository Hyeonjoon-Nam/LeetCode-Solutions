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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // ================================
        // Approach 1: Recursive range partitioning
        // - Time  Complexity: O(N)
        //   (Visiting each node once and O(1) index lookup using HashMap)
        // - Space Complexity: O(N)
        //   (HashMap storage + recursion stack)
        // - Pros: Standard optimal solution for tree reconstruction.
        // - Cons: Requires extra space for the index map.
        // ================================
        preorderIndex = 0;

        for (int i = 0; i < inorder.size(); i++) {
            inorderIndexMap[inorder[i]] = i;
        }
        return arrayToTree(preorder, 0, preorder.size() - 1);
    }
    int preorderIndex = 0;
    unordered_map<int, int> inorderIndexMap;
    TreeNode* arrayToTree(vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr;

        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);
        
        root->left = arrayToTree(preorder, left, inorderIndexMap[rootValue] - 1);
        root->right = arrayToTree(preorder, inorderIndexMap[rootValue] + 1, right);
        return root;
    }
};