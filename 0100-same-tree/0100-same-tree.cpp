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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // ================================
        // Approach 1: Recursive DFS
        // - Time  Complexity: O(N)
        //   (N is the minimum number of nodes in the two trees. Visits each node once)
        // - Space Complexity: O(H)
        //   (H is the height of the tree. Recursive stack depth.)
        // - Pros: Concise.
        // - Cons: Risk of stack overflow on very deep trees.
        // ================================
        // if (p == nullptr && q == nullptr) return true;
        // else if (p == nullptr) return false;
        // else if (q == nullptr) return false;
        // else if (p->val != q->val) return false;

        // return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

        // ================================
        // Approach 2: Iterative BFS
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;

        queue<pair<TreeNode*, TreeNode*>> myQ;
        myQ.push({p, q});

        while (!myQ.empty()) {
            int levelSize = myQ.size();

            for (int i = 0; i < levelSize; i++) {
                auto& it = myQ.front();
                myQ.pop();

                TreeNode* t1 = it.first;
                TreeNode* t2 = it.second;

                if (t1 == nullptr && t2 == nullptr) continue;
                if (t1 == nullptr || t2 == nullptr) return false;

                if (t1->val != t2->val) return false;

                myQ.push({t1->left, t2->left});
                myQ.push({t1->right, t2->right});
            }
        }
        return true;
    }
};