class DetectSquares {
public:
    DetectSquares() {
        // ================================
        // Approach 1: 
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================

    }
    
    void add(vector<int> point) {
        m[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int px = point[0];
        int py = point[1];
        int total = 0;

        for (const auto& [coord, count] : m) {
            int x = coord.first;
            int y = coord.second;

            if (abs(px - x) != abs(py - y) || px == x) continue;

            if (m.count({x, py}) && m.count({px, y})) {
                total += count * m[{x, py}] * m[{px, y}];
            }
        }
        return total;
    }

private:
    map<pair<int, int>, int> m;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */