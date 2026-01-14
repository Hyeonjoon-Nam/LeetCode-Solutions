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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // ================================
        // Approach 1: Store in vector and rebuild
        // - Time  Complexity: O(N)
        //   (Traverse list to vector: O(N), reverse chunks: O(N), rebuild: O(N))
        // - Space Complexity: O(N)
        //   (Vector stores N values, and new ListNode instances are created)
        // - Pros: Intuitive and less error-prone in pointer logic
        // - Cons: High memory overhead
        // ================================
        // if (head == nullptr) return nullptr;
        // ListNode* temp = head;
        // vector<int> v;
        // while (temp != nullptr) {
        //     v.push_back(temp->val);
        //     temp = temp->next;
        // }
        // int n = v.size();
        // if (k > n) return head;

        // for (int i = 0; i + k <= n; i += k) {
        //     reverse(v.begin() + i, v.begin() + i + k);
        // }

        // ListNode dummy(0);
        // ListNode* point = &dummy;
        // for (int x : v) {
        //     point->next = new ListNode(x);
        //     point = point->next;
        // }
        
        // return dummy.next;

        // ================================
        // Approach 2: In-place reversal with constant space
        // - Time  Complexity: O(N)
        //   (Each node is visited and its pointer modified exactly once)
        // - Space Complexity: O(1)
        //   (Constant space used for pointers)
        // - Pros: Momory efficient, optimal
        // - Cons: Complex pointer management
        // ================================
        if (head == nullptr || k == 1) return head;

        ListNode dummy(0, head);
        ListNode* groupPrev = &dummy;

        while (true) {
            ListNode* kth = getKth(groupPrev, k);
            if (kth == nullptr) break;

            ListNode* groupNext = kth->next;

            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;
            while(curr != groupNext) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }
        return dummy.next;
    }

    ListNode* getKth(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};