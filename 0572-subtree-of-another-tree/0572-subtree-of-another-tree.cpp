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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // ================================
        // Approach 1: Double recursive DFS
        // - Time  Complexity: O(M * N)
        //   (M is the number of nodes in root, N is the number of nodes in subRoot)
        // - Space Complexity: O(H)
        //   (H is the height of the root tree due to recursino stack.)
        // - Pros: Highly modular.
        // - Cons: Inefficient if many nodes have the same value.
        // ================================
        if (subRoot == nullptr) return true;
        if (root == nullptr) return false;

        if (isSameTree(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);

        // ================================
        // Approach 2: String serialization
        // - Time  Complexity: O(M + N)
        //   (Serialization takes O(M + N), and string search is very efficient.)
        // - Space Complexity: O(M + N)
        //   (Stores the serialized strings of both trees)
        // - Pros: Faster than the first approach.
        // - Cons: Requires carefull delimiter/null handling.
        // ================================
        // if (!subRoot) return true;
        // if (!root) return false;

        // string s1 = Serialize(root);
        // string s2 = Serialize(subRoot);
        
        // return s1.find(s2) != string::npos;
    }

    // For approach 1
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q || p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right); 
    }

    // For approach 2
    string Serialize(TreeNode* root) {
        if (!root) return ",#";
        
        return "," + to_string(root->val) + Serialize(root->left) + Serialize(root->right);
    }
};