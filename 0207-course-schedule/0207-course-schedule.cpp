class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // ================================
        // Approach 1: DFS
        // - Time  Complexity: O(V + E)
        //   (V is numCourses, E is prerequisites.size(). Each node and edge is visited once.)
        // - Space Complexity: O(V + E)
        //   (Adjacency list takes O(V + E), state array and recursion stack takes O(V))
        // - Pros: Optimal.
        // - Cons: Risk of recursion stack overflow.
        // ================================
        vector<vector<int>> adj(numCourses);
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> state(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (hasCycle(i, adj, state)) return false;
            }
        }
        return true;
    }

    bool hasCycle(int curr, vector<vector<int>>& adj, vector<int>& state) {
        if (state[curr] == 1) return true;
        if (state[curr] == 2) return false;

        state[curr] = 1;
        for (int next : adj[curr]) {
            if (hasCycle(next, adj, state)) return true;
        }
        state[curr] = 2;
        return false;
    }
};