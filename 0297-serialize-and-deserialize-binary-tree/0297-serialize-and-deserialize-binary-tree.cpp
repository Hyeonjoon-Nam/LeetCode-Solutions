/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#";

        string res = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr) {
                res.append(to_string(curr->val) + ",");
                //res += to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            } else {
                //res += "null,";
                res.append("null,");
            }
        }
        cout<<res<<endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "#") return nullptr;

        vector<string> nodes = split(data, ',');

        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < nodes.size()) {
            TreeNode* parent = q.front();
            q.pop();

            if (nodes[i] != "null") {
                parent->left = new TreeNode(stoi(nodes[i]));
                q.push(parent->left);
            }
            i++;

            if (i < nodes.size() && nodes[i] != "null") {
                parent->right = new TreeNode(stoi(nodes[i]));
                q.push(parent->right);
            }
            i++;
        }
        return root;
    }

    vector<string> split(const string& str, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(str);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));