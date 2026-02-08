class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // ================================
        // Approach 1: Dijkstra
        // - Time  Complexity: O(N + E log N)
        //   (N is the number of nodes, E is the number of total edges in the given network.)
        // - Space Complexity: O(N + E)
        //   (Adjacency list and distance array.)
        // - Pros: Optimal.
        // - Cons: Cannot handle negative edge weights.
        // ================================
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            res = max(res, dist[i]);
        }
        return res;
    }
};