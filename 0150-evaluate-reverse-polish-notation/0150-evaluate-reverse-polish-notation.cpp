class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // ================================
        // Approach 1: Stack
        // - Time  Complexity: O(N)
        //   (Iterate through each token once, stack operation are O(1))
        // - Space Complexity: O(N)
        //   (In the worst case, the stack stores all numbers before an operator)
        // - Pros: Naturally follows the logic, efficient
        // - Cons: Linear space required for the stack
        // ================================
        stack<int> stk;

        for (string s : tokens)
        {
            if (s == "+")
            {
                int n1 = stk.top(); stk.pop();
                int n2 = stk.top(); stk.pop();
                stk.push(n2 + n1);
            }
            else if (s == "-")
            {
                int n1 = stk.top(); stk.pop();
                int n2 = stk.top(); stk.pop();
                stk.push(n2 - n1);
            }
            else if (s == "*")
            {
                int n1 = stk.top(); stk.pop();
                int n2 = stk.top(); stk.pop();
                stk.push(n2 * n1);
            }
            else if (s == "/")
            {
                int n1 = stk.top(); stk.pop();
                int n2 = stk.top(); stk.pop();
                stk.push(n2 / n1);
            }
            else
            {
                int num = stoi(s);
                stk.push(num);
            }
        }
        return stk.top();
    }
};