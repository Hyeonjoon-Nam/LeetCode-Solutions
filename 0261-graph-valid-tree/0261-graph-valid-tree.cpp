class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
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

    void dfs(int curr, vector<vector<int>>& adj, unordered_set<int>& visited) {
        if (visited.count(curr)) return;
        visited.insert(curr);
        for (int neighbor : adj[curr]) {
            dfs(neighbor, adj, visited);
        }
    }
};