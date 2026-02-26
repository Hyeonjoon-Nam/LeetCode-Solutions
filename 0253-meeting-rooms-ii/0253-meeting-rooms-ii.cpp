class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // ================================
        // Approach 1: Sorting + Priority queue
        // - Time  Complexity: O(N log N)
        //   (Sorting takes O(N log N), top(), push(), pop() takes O(log N) and we do it N times, so O(N log N))
        // - Space Complexity: O(N)
        //   (In the worst case, priority queue can be sized N)
        // - Pros: Intuitive, optimal.
        // - Cons:  
        // ================================
        int n = intervals.size();
        if (n <= 1) return n;

        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> minHeap;

        minHeap.push(intervals[0][1]);

        for (int i = 1; i < n; i++) {
            if (minHeap.top() <= intervals[i][0]) {
                minHeap.pop();
            }
            minHeap.push(intervals[i][1]);
        }
        return minHeap.size();
    }
};