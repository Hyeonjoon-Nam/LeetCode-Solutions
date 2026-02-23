class Solution {
public:
    string multiply(string num1, string num2) {
        // ================================
        // Approach 1: Vertical Multiplication
        // - Time  Complexity: O(M * N)
        //   (M = num1.length(), N = num2.length(). We perform a nested loop for each digit.)
        // - Space Complexity: O(M + N)
        //   (The result can be at most M+N digits.)
        // - Pros:  
        // - Cons: 
        // ================================
        if (num1 == "0" || num2 == "0") return "0";

        int n1 = num1.size(), n2 = num2.size();
        vector<int> res(n1 + n2, 0);

        for (int i = n1 - 1; i >= 0; --i) {
            for (int j = n2 - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                
                int p1 = i + j, p2 = i + j + 1;
                int sum = mul + res[p2];

                res[p2] = sum % 10;
                res[p1] += sum / 10;
            }
        }

        string ans = "";
        for (int p : res) {
            if (!(ans.empty() && p == 0)) {
                ans.push_back(p + '0');
            }
        }

        return ans.empty() ? "0" : ans;
    }
};