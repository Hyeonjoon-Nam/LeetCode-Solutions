/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> oldToNew;

public:
    Node* cloneGraph(Node* node) {
        // ================================
        // Approach 1: DFS
        // - Time  Complexity: O(V + E)
        //   (V is the number of nodes, E is the number of edges. Each node and edge is visited once.)
        // - Space Complexity: O(V)
        //   (O(V) to store the map and O(V) the recursion stack in the worst case.)
        // - Pros: Intuitive.
        // - Cons: Risk of stack overflow.
        // ================================
        if (!node) return nullptr;

        if (oldToNew.find(node) != oldToNew.end()) {
            return oldToNew[node];
        }

        Node* copy = new Node(node->val);
        oldToNew[node] = copy;

        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(neighbor));
        }

        return copy;
    }
};