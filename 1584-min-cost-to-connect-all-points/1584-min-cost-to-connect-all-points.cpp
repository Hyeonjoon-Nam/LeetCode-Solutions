class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // ================================
        // Approach 1: Prim's Algorithm
        // - Time  Complexity: O(N² log N)
        //   (Since it's a complete graph, E = O(N²). Each of the E edges can be added to the priority queue, taking log E time)
        // - Space Complexity: O(N²)
        //   (To store the edges in the priority queue in the worst case.)
        // - Pros: Very efficient for dense graphs where E is close to V².
        // - Cons: Calculating all N² edges can be memory-intensive.
        // ================================
        int n = points.size();
        int edgesUsed = 0;
        int mstCost = 0;
        vector<bool> inMST(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, 0});

        while (edgesUsed < n) {
            auto [cost, curr] = pq.top();
            pq.pop();

            if (inMST[curr]) continue;

            inMST[curr] = true;
            mstCost += cost;
            edgesUsed++;

            for (int next = 0; next < n; next++) {
                if (!inMST[next]) {
                    int dist = abs(points[curr][0] - points[next][0]) + 
                               abs(points[curr][1] - points[next][1]);
                    pq.push({dist, next});
                }
            }
        }
        return mstCost;
    }
};