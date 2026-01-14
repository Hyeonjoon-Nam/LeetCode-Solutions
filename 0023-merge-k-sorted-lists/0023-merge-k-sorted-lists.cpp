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
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        ListNode dummy(0);
        ListNode* head = &dummy;
        vector<int> temp;
        for (ListNode* l : lists) {
            while (l != nullptr) {
                temp.push_back(l->val);
                l = l->next;
            }
        }
        sort(temp.begin(), temp.end());

        for (int x : temp) {
            head->next = new ListNode(x);
            head = head->next;
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
    }
};