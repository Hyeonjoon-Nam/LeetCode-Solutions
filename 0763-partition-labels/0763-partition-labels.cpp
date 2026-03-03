class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last_idx[26] = {0};

        for (int i = 0; i < s.length(); ++i) {
            last_idx[s[i] - 'a'] = i;
        }

        vector<int> res;
        int size = 0;
        int current_end = 0;

        for (int i = 0; i < s.length(); ++i) {
            current_end = max(last_idx[s[i] - 'a'], current_end);
            ++size;

            if (i == current_end) {
                res.push_back(size);
                size = 0;
            }
        }

        return res;
    }
};