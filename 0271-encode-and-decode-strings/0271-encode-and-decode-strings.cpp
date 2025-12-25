class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ret;
        for (const string& s : strs)
        {
            ret += to_string(s.size()) + "#" + s;
        }
        return ret;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ret;
        int i = 0;

        while (i < s.size())
        {
            int j = i;
            while (s[j] != '#')
            {
                j++;
            }

            int len = stoi(s.substr(i, j - i));
            i = j + 1;

            ret.push_back(s.substr(i, len));

            i += len;
        }
        return ret;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));