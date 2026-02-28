class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize) return false;
        
        map<int, int> count;
        for (int x : hand) {
            ++count[x];
        }

        for (auto& [num, cnt] : count) {
            if (cnt <= 0) continue;

            while (count[num] > 0) {
                for (int i = 0; i < groupSize; ++i) {
                    cout<<num+i<<endl;
                    if (count[num + i] <= 0) return false;
                    else --count[num + i];
                }
            }
            
        }

        return true;
    }
};