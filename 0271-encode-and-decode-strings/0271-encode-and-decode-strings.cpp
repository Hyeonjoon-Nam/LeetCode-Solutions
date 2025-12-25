class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        // ================================
        // Approach 1: 
        // - Time  Complexity: O(N)
        //   (Both encode/decode visit each characters once)
        // - Space Complexity: O(1)
        //   (Excluding the result storage, only constant extra space used)
        // - Pros: Robust. Handles any character (including delimiters) within strings.
        // - Cons: Requires string-to-int conversion during decoding.
        // ================================
        string ret;
        for (const string& s : strs)
        {
            ret += to_string(s.size()) + "#" + s;
        }
        return ret;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        // ================================
        // Approach 1
        // ================================
        vector<string> ret;

        std::string_view sv(s); 
        size_t i = 0;

        while (i < sv.size()) {
            size_t j = sv.find('#', i);
            
            int len = 0;
            for (size_t k = i; k < j; ++k) {
                len = len * 10 + (sv[k] - '0');
            }
            
            i = j + 1;

            ret.emplace_back(sv.substr(i, len));

            i += len;
        }
        return ret;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));