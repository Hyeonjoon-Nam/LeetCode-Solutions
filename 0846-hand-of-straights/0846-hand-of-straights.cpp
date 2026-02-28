class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // ================================
        // Approach 1: Map
        // - Time  Complexity: O(N log N + N * groupSize)
        //   (Inserting takes O(N log N). The while loop processes cards one by one.)
        // - Space Complexity: O(N)
        //   (For the map.)
        // - Pros: Intuitive.
        // - Cons: Not optimal.
        // ================================
        // if (hand.size() % groupSize) return false;
        
        // map<int, int> count;
        // for (int x : hand) {
        //     ++count[x];
        // }

        // for (auto& [num, cnt] : count) {
        //     if (cnt <= 0) continue;

        //     while (count[num] > 0) {
        //         for (int i = 0; i < groupSize; ++i) {
        //             if (count[num + i] <= 0) return false;
        //             else --count[num + i];
        //         }
        //     }
            
        // }

        // return true;


        // ================================
        // Approach 2: Map (Optimized)
        // - Time  Complexity: O(N log N + N * groupSize)
        //   (Same as above.)
        // - Space Complexity: O(N)
        //   (For the map.)
        // - Pros: Better than approach 1.
        // - Cons: 
        // ================================
        // if (hand.size() % groupSize) return false;
        
        // map<int, int> count;
        // for (int x : hand) {
        //     ++count[x];
        // }

        // for (auto& [num, cnt] : count) {
        //     if (cnt <= 0) continue;

        //     int needed = cnt;

        //     for (int i = 0; i < groupSize; ++i) {
        //         if (count[num + i] < needed) return false;
                    
        //         count[num + i] -= needed;
        //     }
            
        // }

        // return true;

        // ================================
        // Approach 3: Unordered Map + Reverse Decrement
        // - Time  Complexity: O(N)
        //   (Building the map takes O(N).)
        // - Space Complexity: O(N)
        //   (For the unordered_map.)
        // - Pros: Optimal
        // - Cons: 
        // ================================
        if (hand.size() % groupSize != 0) {
            return false;
        }

        unordered_map<int, int> cardCount;
        for (int card : hand) {
            cardCount[card]++;
        }

        for (int card : hand) {
            int startCard = card;
            
            while (cardCount[startCard - 1]) {
                startCard--;
            }

            while (startCard <= card) {
                while (cardCount[startCard]) {
                    for (int nextCard = startCard; nextCard < startCard + groupSize; nextCard++) {
                        if (!cardCount[nextCard]) {
                            return false;
                        }
                        cardCount[nextCard]--;
                    }
                }
                startCard++;
            }
        }

        return true;
    }
};