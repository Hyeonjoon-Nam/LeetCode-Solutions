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
        // - Time  Complexity: O(N)
        //   (Iterate each list once, iterate vector)
        // - Space Complexity: O(N)
        //   (To store elements to a vector)
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
        // Approach 2: One pass
        // - Time  Complexity: O(N)
        //   ()
        // - Space Complexity: O(1)
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        ListNode* head = new ListNode(0);
        ListNode* ans = head;

        while (true) {
            if (list1 == nullptr && list2 == nullptr) {
                break;
            } else if (list1 == nullptr) {
                head->next = list2;
                list2 = list2->next;
            } else if (list2 == nullptr) {
                head->next = list1;
                list1 = list1->next;
            } else {
                int val1 = list1->val;
                int val2 = list2->val;
                if (val1 < val2) {
                    head->next = list1;
                    list1 = list1->next;
                } else {
                    head->next = list2;
                    list2 = list2->next;
                }
            }
            head = head->next;
        }
        return ans->next;
    }
};