class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // ================================
        // Approach 1: BFS
        // - Time  Complexity: O(M² * N)
        //   (M is the length of each word and N is the total number of words in the input word list.)
        // - Space Complexity: O(M² * N)
        //   (To store the word set and the BFS queue.)
        // - Pros: Guarantees the shortest path in an unweighted graph.
        // - Cons: Can consume significant memory if the word list is huge.
        // ================================
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto [word, level] = q.front();
            q.pop();

            if (word == endWord) return level;

            for (int i = 0; i < word.length(); i++) {
                char originalChar = word[i];

                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == originalChar) continue;
                    word[i] = c;

                    if (dict.find(word) != dict.end()) {
                        q.push({word, level + 1});
                        dict.erase(word);
                    }
                }
                word[i] = originalChar;
            }
        }

        return 0;
    }
};