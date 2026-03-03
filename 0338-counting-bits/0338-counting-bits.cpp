class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            res[i] = count(i);
        }
        return res;
    }

    int count(int n) {
        int res = 0;
        while (n) {
            res += n & 0x1;
            n >>= 1;
        }
        return res;
    }
};