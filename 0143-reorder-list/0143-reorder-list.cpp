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
    void reorderList(ListNode* head) {
        // ================================
        // Approach 1: Split, Reverse, and Merge
        // - Time  Complexity: O(N)
        //   (Finding middle takes O(N/2), Reverse takes O(N/2), Merge takes O(N/2), so totally O(N))
        // - Space Complexity: O(1)
        //   (Constant space used for pointers)
        // - Pros: OPtimal
        // - Cons: 
        // ================================
        if (head == nullptr) return;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = slow;
        ListNode* temp;
        while (curr != nullptr) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        ListNode* first = head;
        ListNode* second = prev;
        
        while (second->next != nullptr) {
            temp = first->next;
            first->next = second;
            first = temp;
            temp = second->next;
            second->next = first;
            second = temp;
        }
    }
};