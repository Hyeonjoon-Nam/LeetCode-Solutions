class Solution {
public:
    bool isValid(string s) {
        // ================================
        // Approach 1: 
        // - Time  Complexity: O()
        //   ()
        // - Space Complexity: O()
        //   ()
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