class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // ================================
        // Approach 1: Dijkstra
        // - Time  Complexity: O(E * K * (E + log(E * K)))
        //   (In the worst case, we can process each edge multiple times for different stop counts within the limit K.)
        // - Space Complexity: O(V + E)
        //   (Adjacency list stores E edges, stops array stores V nodes, and the priority queue can grow relative to edges.)
        // - Pros: Guarantees the absolute minimum cost due to PQ sorting.
        // - Cons: Complex..
        // ================================
        vector<vector<pair<int, int>>> adj(n);
        for (auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }
        
        vector<int> stops(n, INT_MAX);

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {src, 0}});

        while (!pq.empty()) {
            auto curr = pq.top(); pq.pop();
            int currentCost = curr.first;
            int u = curr.second.first;
            int stopCount = curr.second.second;

            if (u == dst) return currentCost;
            if (stopCount > k || stopCount >= stops[u]) continue;

            stops[u] = stopCount;

            for (auto& next : adj[u]) {
                int v = next.first;
                int weight = next.second;

                pq.push({currentCost + weight, {v, stopCount + 1}});
            }
        }
        return -1;
    }
};