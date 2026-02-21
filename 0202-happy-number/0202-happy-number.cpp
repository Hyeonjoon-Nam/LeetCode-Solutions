class Solution {
public:
    bool isHappy(int n) {
        // ================================
        // Approach 1: Hashset  
        // - Time  Complexity: O(log n)
        //   (The number of digits decreases logarithmically, and cycles are small.)
        // - Space Complexity: O(log n)
        //   (Stores each intermediate sum in an unordered_set.)
        // - Pros: Intuitive.
        // - Cons: Uses extra memory.
        // ================================
        // unordered_set<int> seen;
        
        // while (true) {
        //     if (n == 1) return true;
        //     if (seen.find(n) != seen.end()) return false;
        //     seen.insert(n);
        //     n = happy(n);
        // }
        // return true;

        
        // ================================
        // Approach 2: Floyd's Algorithm  
        // - Time  Complexity: O(log n)
        //   (Similar to Hashset, but involoves a constant factor for two pointers.)
        // - Space Complexity: O(1)
        //   (Only uses two pointers.)
        // - Pros: Memory efficient.
        // - Cons: Slightly more complex to implement.
        // ================================
        int slow = n;
        int fast = happy(n);

        while (fast != 1 && slow != fast) {
            slow = happy(slow);
            fast = happy(happy(fast));
        }

        return fast == 1;
    }

    // For approach 1 & 2
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