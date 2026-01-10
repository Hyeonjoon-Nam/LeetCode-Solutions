/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // ================================
        // Approach 1: Count and remove
        // - Time  Complexity: O(N)
        //   (Iterate each elements two times)
        // - Space Complexity: O(1)
        //   (Constant space used for pointers)
        // - Pros: Fast and space efficient
        // - Cons: Doens't meet the follow-up requirement (one pass)
        // ================================
        // if (head == nullptr) return nullptr;
        // int size = 0;
        // ListNode* temp = head;
        // while (temp != nullptr) {
        //     size++;
        //     temp = temp->next;
        // }
        // if (n > size) return head;
        // if (n == size) return head->next;

        // int target = size - n;
        // temp = head;
        // for (int i = 0; i < target - 1; i++) {
        //     temp = temp->next;
        // }
        // temp->next = temp->next->next;

        // return head;

        // ================================
        // Approach 2: One pass (Two pointers)
        // - Time  Complexity: O(N)
        //   (Traverse the list exactly once)
        // - Space Complexity: O(1)
        //   (Constant space used for pointers)
        // - Pros: Optimal
        // - Cons: Slightly more abstract logic
        // ================================
        if (head == nullptr) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        for (int i = 0; i < n; i++) {
            if (fast == nullptr) return head;
            fast = fast->next;
        }

        if (fast == nullptr) return head->next;

        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};