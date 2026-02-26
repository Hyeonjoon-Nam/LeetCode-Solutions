class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        // ================================
        // Approach 1: Sorting
        // - Time  Complexity: O(N log N)
        //   (Sorting takes O(N log N))
        // - Space Complexity: O(log N) or O(N)
        //   (C++ quick sort takes O(log N) on average, but the worst case, O(N))
        // - Pros: Simple, optimal.
        // - Cons: Modifies the original intervals array. 
        // ================================
        if (intervals.size() < 2) return true;
        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < intervals.size() - 1; i++) {
            if (intervals[i][1] > intervals[i + 1][0]) return false;
        }
        return true;
    }
};