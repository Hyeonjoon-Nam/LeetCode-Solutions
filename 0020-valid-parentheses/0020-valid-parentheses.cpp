class Solution {
public:
    bool isValid(string s) {
        // ================================
        // Approach 1: stack
        // - Time  Complexity: O(N)
        //   (Iterate all the elements once)
        // - Space Complexity: O(N)
        //   (To store to stack)
        // - Pros: 
        // - Cons: 
        // ================================
        std::stack<int> myS;

        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                myS.push(c);
            }
            else if (myS.empty())
                return false;
            else if (c == ')')
            {
                if (myS.top() == '(')
                    myS.pop();
                else
                    return false;
            }
            else if (c == '}')
            {
                if (myS.top() == '{')
                    myS.pop();
                else
                    return false;
            }
            else if (c == ']')
            {
                if (myS.top() == '[')
                    myS.pop();
                else
                    return false;
            }
        }

        return myS.empty();
    }
};