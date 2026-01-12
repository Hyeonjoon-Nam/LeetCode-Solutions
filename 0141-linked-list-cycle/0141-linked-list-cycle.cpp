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
        // - Time  Complexity: O(N)
        //   (Iterate each elements once)
        // - Space Complexity: O(N)
        //   (To store data to unordered_set)
        // - Pros: Intuitive
        // - Cons: Uses extra space
        // ================================
        // unordered_set<ListNode*> hash;
        // while (head != nullptr) {
        //     if (hash.find(head) != hash.end()) return true;
        //     hash.insert(head);
        //     head = head->next;
        // }
        // return false;
        
        // ================================
        // Approach 2: Two pointers
        // - Time  Complexity: O(N)
        //   (Linearly iterate)
        // - Space Complexity: O(1)
        //   (Constant space used for pointers)
        // - Pros: Space efficient
        // - Cons: 
        // ================================
        if (head == nullptr) return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            if (fast == slow) return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};