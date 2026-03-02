class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> current(3, INT_MIN);

        for (const vector<int>& v : triplets) {
            if (v[0] > target[0] || v[1] > target[1] || v[2] > target[2])
                continue;
            
            current[0] = max(current[0], v[0]);
            current[1] = max(current[1], v[1]);
            current[2] = max(current[2], v[2]);
        }

        return current[0] == target[0] && current[1] == target[1] && current[2] == target[2];
    }
};