class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // ================================
        // Approach 1: Max-Heap (Fixed size k)
        // - Time  Complexity: O(N log k)
        //   (N points are processed, and each heap operation taeks O(log k))
        // - Space Complexity: O(k)
        //   (Stores at most k elements in the priority queue.)
        // - Pros: Efficient memory usage, faster than sorting all points.
        // - Cons: Only gives the top k without total order of other points.
        // ================================
        priority_queue<pair<int, int>> maxHeap;

        for (int i = 0; i < points.size(); i++) {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            maxHeap.push({dist, i});

            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        vector<vector<int>> sol;
        while (!maxHeap.empty()) {
            sol.push_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }
        return sol;
    }
};