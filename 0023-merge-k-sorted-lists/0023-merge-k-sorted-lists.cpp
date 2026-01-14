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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // ================================
        // Approach 1: 
        // - Time  Complexity: O(N log N)
        //   ()
        // - Space Complexity: O(N log N)
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        // ListNode dummy(0);
        // ListNode* head = &dummy;
        // vector<int> temp;
        // for (ListNode* l : lists) {
        //     while (l != nullptr) {
        //         temp.push_back(l->val);
        //         l = l->next;
        //     }
        // }
        // sort(temp.begin(), temp.end());

        // for (int x : temp) {
        //     head->next = new ListNode(x);
        //     head = head->next;
        // }

        // return dummy.next;

        // ================================
        // Approach 2: 
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        if (lists.empty()) return nullptr;

        ListNode* res = nullptr;
        for (ListNode* l : lists) {
            res = mergeTwoLists(res, l);
        }
        return res;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};