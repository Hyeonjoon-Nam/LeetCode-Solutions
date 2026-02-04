class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // ================================
        // Approach 1: DFS 
        // - Time  Complexity: O(V + E) 
        //   (V is numCourses, E is prerequisites.size(). Each node and edge is visited once.)
        // - Space Complexity: O(V + E)
        //   (Adjacency list O(V+E), state/result arrays and recursion stack O(V))
        // - Pros: Optimal.
        // - Cons: Recursive overhead, requires reversing the post-order result.
        // ================================
        vector<vector<int>> adj(numCourses);
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }
        vector<int> state(numCourses, 0);
        vector<int> res;

        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (hasCycle(i, adj, state, res)) return {};
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }

    bool hasCycle(int curr, vector<vector<int>>& adj, vector<int>& state, vector<int>& res) {
        if (state[curr] == 1) return true;
        if (state[curr] == 2) return false;

        state[curr] = 1;
        for (int next : adj[curr]) {
            if (hasCycle(next, adj, state, res)) return true;
        }
        state[curr] = 2;
        res.push_back(curr);
        return false;
    }
};