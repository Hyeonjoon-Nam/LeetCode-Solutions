class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 0) return true;

        vector<bool> possible(n, false);
        possible[0] = true;

        for (int i = 0; i < n; ++i) {
            if (!possible[i]) return false;

            for (int j = 0; j < nums[i]; ++j) {
                int index = i + j + 1;
                if (index >= n) break;
                else possible[index] = true;
            }
        }
        return true;
    }
};