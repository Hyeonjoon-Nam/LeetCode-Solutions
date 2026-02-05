class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // ============================================================
        // Approach 1: DFS
        // - Time  Complexity: O(V + E)
        //   (V is n, E is edges.size(). Each node and edge is visited once.)
        // - Space Complexity: O(V + E)
        //   (Adjacency list takes O(V+E), visited set and recursion stack take O(V).)
        // - Pros: Intuitive and easy to implement. Works perfectly for finding sub-graphs.
        // - Cons: Risk of Stack Overflow in very deep/linear graphs.
        // ============================================================
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> visited(n);

        int count = 0;

        for (int i = 0; i < n; i++) {
            if (visited.count(i)) continue;
            
            dfs(i, adj, visited);
            count++;
        }

        return count;
    }

    void dfs(int curr, vector<vector<int>>& adj, unordered_set<int>& visited) {
        if (visited.count(curr)) return;

        visited.insert(curr);
        for (int neighbor : adj[curr]) {
            dfs(neighbor, adj, visited);
        }
    }
};