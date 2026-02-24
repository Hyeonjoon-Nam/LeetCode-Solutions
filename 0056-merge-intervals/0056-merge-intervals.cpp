class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // ================================
        // Approach 1: 
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        // sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
        //     return a[0] < b[0];
        // });

        // vector<vector<int>> res;

        // for (vector<int>& v : intervals) {
        //     if (!res.empty()) {
        //         if (res.back()[1] >= v[0]) {
        //             int start = min(res.back()[0], v[0]);
        //             int end = max(res.back()[1], v[1]);

        //             res.pop_back();
        //             res.push_back({start, end});
        //         }
        //         else
        //             res.push_back(v);
        //     }
        //     else
        //         res.push_back(v);
        // }

        // return res;

        // ================================
        // Approach 1: 
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> res;

        for (vector<int>& v : intervals) {
            if (!res.empty()) {
                if (res.back()[1] >= v[0]) {
                    int end = max(res.back()[1], v[1]);
                    res.back()[1] = end;
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