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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ================================
        // Approach 1: 
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        ListNode dummy(0);
        ListNode* head = &dummy;
        int sum;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int num1, num2;
            if (l1 == nullptr) num1 = 0;
            else num1 = l1->val;
            if (l2 == nullptr) num2 = 0;
            else num2 = l2->val;

            sum = num1 + num2 + carry;
            if (sum >= 10) {
                carry = 1;
                sum -= 10;
            } else {
                carry = 0;
            }
            head->next = new ListNode(sum);
            head = head->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) head->next = new ListNode(carry);

        return dummy.next;
    }
};