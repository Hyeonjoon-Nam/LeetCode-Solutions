class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int prev = nums[0];
        int curr = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            curr = nums[i] + max(prev, 0);
            res = max(res, curr);
            prev = curr;
        }
        return res;
    }
};