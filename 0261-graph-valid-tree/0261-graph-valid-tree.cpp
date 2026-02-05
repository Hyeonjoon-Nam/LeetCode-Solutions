class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
    // ============================================================
    // Approach 1: DFS
    // - Time  Complexity: O(V + E)
    //   (V is the number of nodes, E is the number of edges. We visit each node and edge once.)
    // - Space Complexity: O(V + E)
    //   (Adjacency list stores all edges and nodes. Recursion stack depth can be O(V).)
    // - Pros: Concise.
    // - Cons: Risk of stack overflow on very deep linear graphs.
    // ============================================================
        if (edges.size() != n - 1) return false;

        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visited;
        dfs(0, adj, visited);
        
        return visited.size() == n;
    }

    // For approach 1
    void dfs(int curr, vector<vector<int>>& adj, unordered_set<int>& visited) {
        if (visited.count(curr)) return;
        visited.insert(curr);
        for (int neighbor : adj[curr]) {
            dfs(neighbor, adj, visited);
        }
    }
};