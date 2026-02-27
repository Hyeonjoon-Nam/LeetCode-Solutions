class Solution {
public:
    int jump(vector<int>& nums) {
        int current_end = 0, max_reach = 0;
        int jump_count = 0;
        int n = nums.size();

        for (int i = 0; i < n - 1; ++i) {
            max_reach = max(max_reach, i + nums[i]);
            if (i == current_end) {
                ++jump_count;
                current_end = max_reach;
            }
        }
        return jump_count;
    }
};