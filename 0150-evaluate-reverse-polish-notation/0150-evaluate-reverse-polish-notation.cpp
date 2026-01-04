class Solution {
public:
    int evalRPN(vector<string>& tokens) {
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