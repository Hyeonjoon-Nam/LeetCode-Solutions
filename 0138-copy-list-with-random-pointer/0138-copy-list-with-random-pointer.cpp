/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // ================================
        // Approach 1: Using hash map
        // - Time  Complexity: O(N)
        //   (Iterate each nodes twice)
        // - Space Complexity: O(N)
        //   (To store data to unordered_map)
        // - Pros: 
        // - Cons: Uses extra space
        // ================================
        // if (head == nullptr) return nullptr;

        // unordered_map<Node*, Node*> oldToNew;

        // Node* curr = head;
        // while (curr) {
        //     oldToNew[curr] = new Node(curr->val);
        //     curr = curr->next;
        // }

        // curr = head;
        // while (curr) {
        //     oldToNew[curr]->next = oldToNew[curr->next];
        //     oldToNew[curr]->random = oldToNew[curr->random];
        //     curr = curr->next;
        // }

        // return oldToNew[head];

        // ================================
        // Approach 2: 
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
        // - Pros: 
        // - Cons: 
        // ================================
        if (head == nullptr) return nullptr;

        Node* ptr = head;
        while (ptr != nullptr) {
            Node* newNode = new Node(ptr->val, nullptr, nullptr);
            newNode->next = ptr->next;
            ptr->next = newNode;
            ptr = newNode->next;
        }

        ptr = head;
        while (ptr != nullptr) {
            ptr->next->random = (ptr->random != nullptr) ? ptr->random->next : nullptr;
            ptr = ptr->next->next;
        }

        Node* ptr_old_list = head;
        Node* ptr_new_list = head->next;
        Node* head_old = head->next;
        while (ptr_old_list != nullptr) {
            ptr_old_list->next = ptr_old_list->next->next;
            ptr_new_list->next = (ptr_new_list->next != nullptr) ? ptr_new_list->next->next : nullptr;
            ptr_old_list = ptr_old_list->next;
            ptr_new_list = ptr_new_list->next;
        }
        return head_old;
    }
};