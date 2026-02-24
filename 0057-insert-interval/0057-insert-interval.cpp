class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // ================================
        // Approach 1: Append and Merge
        // - Time  Complexity: O(N log N)
        //   (Pushing back takes O(1), but merge() sorts the entire array.)
        // - Space Complexity: O(N)
        //   (Allocates a new result vector, plus O(log N) for sorting space.)
        // - Pros: Simple.
        // - Cons: Not optimal time complexity.
        // ================================
        // intervals.push_back(newInterval);
        // return merge(intervals);

        // ================================
        // Approach 2: Linear Traversal
        // - Time  Complexity: O(N)
        //   (Single pass through the intervals array.)
        // - Space Complexity: O(1)
        //   (Excluding the result vector, only use a few integer pointers.)
        // - Pros: Optimal.
        // - Cons: Allocates a new vector.
        // ================================
        vector<vector<int>> res;
        int n = intervals.size();
        int i = 0;

        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            ++i;
        }

        while (i < n && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            ++i;
        }
        res.push_back(newInterval);

        while (i < n) {
            res.push_back(intervals[i]);
            ++i;
        }

        return res;
    }

    // For approach 1
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> res;

        for (vector<int>& v : intervals) {
            if (!res.empty()) {
                if (res.back()[1] >= v[0]) {
                    int start = min(res.back()[0], v[0]);
                    int end = max(res.back()[1], v[1]);

                    res.pop_back();
                    res.push_back({start, end});
                }
                else
                    res.push_back(v);
            }
            else
                res.push_back(v);
        }

        return res;
    }
};