class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        // ================================
        // Approach 1: Greedy
        // - Time  Complexity: O(N)
        //   (A single linear pass through the triplets array)
        // - Space Complexity: O(1)
        //   (Constant space used.)
        // - Pros: Optimal time and space.
        // - Cons: 
        // ================================
        int max_x = 0, max_y = 0, max_z = 0;

        for (const vector<int>& v : triplets) {
            if (v[0] > target[0] || v[1] > target[1] || v[2] > target[2])
                continue;
            
            max_x = max(max_x, v[0]);
            max_y = max(max_y, v[1]);
            max_z = max(max_z, v[2]);
        }

        return max_x == target[0] && max_y == target[1] && max_z == target[2];
    }
};