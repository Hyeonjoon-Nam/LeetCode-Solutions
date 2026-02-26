class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // ================================
        // Approach 1: Greedy
        // - Time  Complexity: O(N log N)
        //   (Sorting takes O(N log N))
        // - Space Complexity: O(log N)
        //   (Sorting takes O(log N))
        // - Pros: Optimal.
        // - Cons:  
        // ================================
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end());
        
        int count = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < prevEnd) {
                count++;
                prevEnd = min(prevEnd, intervals[i][1]);
            }
            else {
                prevEnd = intervals[i][1];
            }
        }
        return count;
    }
};