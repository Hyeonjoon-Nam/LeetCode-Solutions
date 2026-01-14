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
        // Approach 1: 
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        if (head == nullptr) return nullptr;
        ListNode* temp = head;
        vector<int> v;
        while (temp != nullptr) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        int n = v.size();
        if (k > n) return head;

        for (int i = 0; i + k <= n; i += k) {
            reverse(v.begin() + i, v.begin() + i + k);
        }

        ListNode dummy(0);
        ListNode* point = &dummy;
        for (int x : v) {
            point->next = new ListNode(x);
            point = point->next;
        }
        
        return dummy.next;

        // ================================
        // Approach 1: 
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        // if (head == nullptr) return nullptr;
        // ListNode* temp = head;
        // int n = 1;
        // while (temp != nullptr) {
        //     temp = temp->next;
        //     n++;
        // }
        // if (n < k) return head;
    }
};