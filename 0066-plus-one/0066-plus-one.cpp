class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int n = digits.size();
        int add = 1;

        for (int i = n - 1; i >= 0; i--) {
            int sum = digits[i] + add;
            if (sum == 10) {
                add = 1;
                res.push_back(0);
            }
            else {
                add = 0;
                res.push_back(sum);
            }
        }
        if (add) res.push_back(1);
        reverse(res.begin(), res.end());
        return res;
    }
};