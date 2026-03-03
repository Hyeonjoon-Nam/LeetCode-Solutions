class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            int res = a ^ b;
            int carry = (a & b) << 1;
            a = res;
            b = carry;
        }
        return a;
    }
};