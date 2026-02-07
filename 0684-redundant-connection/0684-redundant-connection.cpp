class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // ================================
        // Approach 1: 
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        int n = edges.size();
        vector<vector<int>> adj(n + 1);

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            vector<bool> visited(n + 1, false);

            if (dfs(u, v, adj, visited)) {
                return edge;
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};

        // ================================
        // Approach 2: 
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        // int n = edges.size();
        // parent.resize(n + 1);
        // for (int i = 1; i <= n; i++) parent[i] = i;

        // for (auto& edge : edges) {
        //     int rootU = find(edge[0]);
        //     int rootV = find(edge[1]);

        //     if (rootU == rootV) {
        //         return edge;
        //     }
        //     parent[rootU] = rootV;
        // }
        // return {};
    }


    // For approach 1
    bool dfs(int curr, int target, vector<vector<int>>& adj, vector<bool> visited) {
        if (curr == target) return true;

        visited[curr] = true;
        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, target, adj, visited)) return true;
            }
        }
        return false;
    }
    
    // For approach 2
    vector<int> parent;
    
    // For approach 2
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
};