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
        // Approach 1: Collect, sort, and rebuild
        // - Time  Complexity: O(N log N)
        //   (N is the total number of nodes, sorting takes O(N log N))
        // - Space Complexity: O(N)
        //   (Storing nodes to a vector)
        // - Pros: Quite fast. std::sort is higly optimized and vector has excellent cache locality.
        // - Cons: High memory usage. Creates new nodes (heap overhead)
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
        // Approach 2: Sequential Merging
        // - Time  Complexity: O(N * k)
        //   (K is the number of lists.)
        // - Space Complexity: O(1)
        //   (Constant space used for pointers)
        // - Pros: Memory efficient.
        // - Cons: Slower (O(N * k)). Frequent pointer chasing causes cache misses.
        // ================================
        // if (lists.empty()) return nullptr;

        // ListNode* res = nullptr;
        // for (ListNode* l : lists) {
        //     res = mergeTwoLists(res, l);
        // }
        // return res;

        // ================================
        // Approach 3: 
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        int amount = lists.size();
        int interval = 1;
        while (interval < amount) {
            for (int i = 0; i < amount - interval; i += interval * 2)
                lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
            interval *= 2;
        }
        return amount > 0 ? lists[0] : NULL;
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