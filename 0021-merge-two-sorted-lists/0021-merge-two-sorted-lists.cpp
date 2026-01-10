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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // ================================
        // Approach 1: Copy and sort
        // - Time  Complexity: O(n+m)
        //   (Iterate each list once, iterate vector)
        // - Space Complexity: O(n+m)
        //   (To store all the elements to a vector)
        // - Pros: Intuitive
        // - Cons: Uses extra space
        // ================================
        // vector<int> sorted;
        // ListNode* temp = list1;
        // while (temp != nullptr) {
        //     sorted.push_back(temp->val);
        //     temp = temp->next;
        // }
        // temp = list2;
        // while (temp != nullptr) {
        //     sorted.push_back(temp->val);
        //     temp = temp->next;
        // }
        // sort(sorted.begin(), sorted.end());
        // ListNode* head = new ListNode(0);
        // ListNode* ans = head;
        // for (int x : sorted) {
        //     head ->next = new ListNode(x);
        //     head = head->next;
        // }
        // return ans->next;

        // ================================
        // Approach 2: One pass iteration
        // - Time  Complexity: O(n+m)
        //   (Iterate)
        // - Space Complexity: O(1)
        //   (Constant space used for pointers)
        // - Pros: Optimal, space efficient
        // - Cons: 
        // ================================
        // ListNode* head = new ListNode(0);
        // ListNode* ans = head;

        // while (true) {
        //     if (list1 == nullptr && list2 == nullptr) {
        //         break;
        //     } else if (list1 == nullptr) {
        //         head->next = list2;
        //         list2 = list2->next;
        //     } else if (list2 == nullptr) {
        //         head->next = list1;
        //         list1 = list1->next;
        //     } else {
        //         int val1 = list1->val;
        //         int val2 = list2->val;
        //         if (val1 < val2) {
        //             head->next = list1;
        //             list1 = list1->next;
        //         } else {
        //             head->next = list2;
        //             list2 = list2->next;
        //         }
        //     }
        //     head = head->next;
        // }
        // return ans->next;

        // ================================
        // Approach 3: More concise iteration
        // - Time  Complexity: O(n+m)
        //   ()
        // - Space Complexity: O(1)
        //   (Constant space used for pointers)
        // - Pros: 
        // - Cons: 
        // ================================
        ListNode dummy(-1);
        ListNode* prev = &dummy;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                prev->next = list1;
                list1 = list1->next;
            } else {
                prev->next = list2;
                list2 = list2->next;
            }
            prev = prev->next;
        }
        prev->next = list1 == nullptr ? list2 : list1;
        return dummy.next;
    }
};