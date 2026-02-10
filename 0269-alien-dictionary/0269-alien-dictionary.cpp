class Solution {
public:
    string alienOrder(vector<string>& words) {
        // ================================
        // Approach 1: Topological Sort
        // - Time  Complexity: O(C)
        //   (C is the total number of characters in all words combined.)
        // - Space Complexity: O(1)
        //   (Since the alphabet is limited to 26 characters, the storage for inDegree and aj is constant)
        // - Pros: Efficiently detects cycles and handles multiple dependency rules.
        // - Cons: Requires careful handling of edge cases.
        // ================================
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> inDegree;

        for (string& w : words) {
            for (char c : w) inDegree[c] = 0;
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.length(), s2.length());
            bool foundDifference = false;

            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    if (adj[s1[j]].find(s2[j]) == adj[s1[j]].end()) {
                        adj[s1[j]].insert(s2[j]);
                        inDegree[s2[j]]++;
                    }
                    foundDifference = true;
                    break;
                }
            }
            if (!foundDifference && s1.length() > s2.length()) return "";
        }

        queue<char> q;
        for (auto const& [ch, degree] : inDegree) {
            if (degree == 0) q.push(ch);
        }

        string res = "";
        while (!q.empty()) {
            char curr = q.front(); q.pop();
            res += curr;

            for (char next : adj[curr]) {
                if (--inDegree[next] == 0) q.push(next);
            }
        }
        return res.length() == inDegree.size() ? res : "";
    }
};