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
    ListNode* reverseList(ListNode* head) {
        // ================================
        // Approach 1: Copy and reverse data
        // - Time  Complexity: O(N)
        //   (Iterate all elements step by step)
        // - Space Complexity: O(N)
        //   (To store data to vector)
        // - Pros: Intuitive
        // - Cons: Use extra space
        // ================================
        // ListNode* ans = new ListNode(0);
        // ListNode* save = ans;
        // vector<int> temp;

        // while (head != nullptr)
        // {
        //     temp.push_back(head->val);
        //     head = head->next;
        // }
        // reverse(temp.begin(), temp.end());

        // for (int x : temp)
        // {
        //     ans->next = new ListNode(x);
        //     ans = ans->next;
        // }

        // return save->next;

        // ================================
        // Approach 2: I
        // - Time  Complexity: O(N)
        //   (Iterate each elements step by step)
        // - Space Complexity: O(1)
        //   (Constant space used for pointers)
        // - Pros: Space efficient
        // - Cons: 
        // ================================
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};