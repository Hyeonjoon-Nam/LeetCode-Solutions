class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        
        while (true) {
            if (n == 1) return true;
            if (seen.find(n) != seen.end()) return false;
            seen.insert(n);
            n = happy(n);
        }
        return true;
    }

    int happy(int n) {
        int sum = 0;

        while (n > 0) {
            int remainder = n % 10;
            sum += remainder * remainder;
            n /= 10;
        }

        return sum;
    }
};