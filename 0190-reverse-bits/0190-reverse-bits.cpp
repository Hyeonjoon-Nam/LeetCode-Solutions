class Solution {
public:
    int reverseBits(int n) {
        int res = 0, pow = 31;
        while (n) {
            res += (n & 1) << pow;
            n >>= 1;
            --pow;
        }
        return res;
    }
};