class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // ================================
        // Approach 1: Max-Heap
        // - Time  Complexity: O(N)
        //   (The overall time complexity is O(N log k), since k is 26, log k is constant term.)
        // - Space Complexity: O(1)
        //   (O(26) = O(1))
        // - Pros: Directly simulates the process.
        // - Cons: 
        // ================================
        // int freq[26] = {0};
        // for (char c : tasks) {
        //     freq[c - 'A']++;
        // }

        // priority_queue<int> pq;
        // for (int i = 0; i < 26; i++) {
        //     if (freq[i] > 0) {
        //         pq.push(freq[i]);
        //     }
        // }

        // int time = 0;
        // while (!pq.empty()) {
        //     int cycle = n + 1;
        //     vector<int> store;
        //     int taskCount = 0;

        //     while (cycle-- && !pq.empty()) {
        //         if (pq.top() > 1) {
        //             store.push_back(pq.top() - 1);
        //         }
        //         pq.pop();
        //         taskCount++;
        //     }
        //     for (int& x : store) {
        //         pq.push(x);
        //     }

        //     time += (pq.empty() ? taskCount : n + 1);
        // }
        // return time;

        // ================================
        // Approach 2: 
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        int freq[26] = {};
        int maxCount = 0;

        for (char task : tasks) {
            freq[task - 'A']++;
            maxCount = max(maxCount, freq[task - 'A']);
        }

        int time = (maxCount - 1) * (n + 1);
        for (int f : freq) {
            if (f == maxCount) {
                time++;
            }
        }

        return max(static_cast<int>(tasks.size()), time);
    }
};