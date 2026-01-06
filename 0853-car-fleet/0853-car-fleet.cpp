class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // ================================
        // Approach 1: 
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        vector<pair<int, int>> cars;
        int n = position.size();

        for (int i = 0; i < n; i++)
        {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end(), [](auto a, auto b)
        {
            return a.first > b.first;
        });

        int fleets = 0;
        double maxTime = 0.0;
        
        for (int i = 0; i < n; i++)
        {
            double time = static_cast<double>(target - cars[i].first) / cars[i].second;
            
            if (time > maxTime)
            {
                fleets++;
                maxTime = time;
            }
        }

        return fleets;
    }
};