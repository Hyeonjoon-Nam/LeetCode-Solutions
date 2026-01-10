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
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        if (head == nullptr) return nullptr;
        int size = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            size++;
            temp = temp->next;
        }
        if (n > size) return head;
        if (n == size) return head->next;

        int target = size - n;
        temp = head;
        for (int i = 0; i < target - 1; i++) {
            temp = temp->next;
        }
        temp->next = temp->next->next;

        return head;
    }
};