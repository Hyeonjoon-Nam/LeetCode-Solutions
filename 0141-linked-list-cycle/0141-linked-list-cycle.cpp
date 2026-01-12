/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // ================================
        // Approach 1: Using hash map
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        unordered_set<ListNode*> hash;
        while (head != nullptr) {
            if (hash.find(head) != hash.end()) return true;
            hash.insert(head);
            head = head->next;
        }
        return false;
    }
};