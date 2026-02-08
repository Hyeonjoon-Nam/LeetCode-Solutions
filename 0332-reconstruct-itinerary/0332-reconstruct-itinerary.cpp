class Solution {
public:
    // For approach 1
    unordered_map<string, multiset<string>> adj;
    vector<string> res;

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // ================================
        // Approach 1: Greedy DFS
        // - Time  Complexity: O(E log E)
        //   (E is the number of tickets, sorting neighbor)
        // - Space Complexity: O(V + E)
        //   (Storing the graph takes O(V+E) and the recursion stack can go up to O(E))
        // - Pros: Guarantees finding the lexical smallest Eulerian path efficiently.
        // - Cons: Risk of stack overflow. 
        // ================================
        for (auto& t : tickets) {
            adj[t[0]].insert(t[1]);
        }

        dfs("JFK");

        reverse(res.begin(), res.end());
        return res;
    }

    // For approach 1
    void dfs(string u) {
        while (!adj[u].empty()) {
            string v = *adj[u].begin();
            adj[u].erase(adj[u].begin());
            dfs(v);
        }
        res.push_back(u);
    }
};