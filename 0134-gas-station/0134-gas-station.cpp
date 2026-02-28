class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // ================================
        // Approach 1: Greedy
        // - Time  Complexity: O(N)
        //   (A single linear pass through the arrays.)
        // - Space Complexity: O(1)
        //   (Constant space used.)
        // - Pros: Optimal.
        // - Cons: 
        // ================================
        int total_gas = 0;
        int current_gas = 0;
        int start_index = 0;
        int n = gas.size();

        for (int i = 0; i < n; ++i) {
            int get = gas[i] - cost[i];

            total_gas += get;
            current_gas += get;

            if (current_gas < 0) {
                start_index = i + 1;
                current_gas = 0;
            }
        }
        if (total_gas < 0) return -1;

        return start_index;
    }
};