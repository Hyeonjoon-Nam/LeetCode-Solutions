class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // ================================
        // Approach 1: Two pointers
        // - Time  Complexity: O(N)
        //   (Iterate each elements in the vector)
        // - Space Complexity: O(1)
        //   (No extra space used)
        // - Pros: Space efficient. 
        // - Cons: 
        // ================================
        // int n = numbers.size();
        // int p0 = 0;
        // int p1 = n - 1;
        // int sum = 0;

        // while (p0 < p1)
        // {
        //     sum = numbers[p0] + numbers[p1];
        //     if (sum == target) return { p0 + 1, p1 + 1 };
        //     else if (sum > target) p1--;
        //     else p0++;
        // }
        // return {};

        
        // ================================
        // Approach 2: Brute Force
        // - Time  Complexity: O(N²)
        //   (Using two for-loop which iterates all the elements in vector)
        // - Space Complexity: O(1)
        //   (No extra space used)
        // - Pros: Intuitive
        // - Cons: Time Limit exceeds 
        // ================================
        // int n = numbers.size();
        // for (int i = 0; i < n - 1; i++)
        // {
        //     for (int j = i + 1; j < n; j++)
        //     {
        //         if (numbers[i] + numbers[j] == target) return { i + 1, j + 1 };
        //     }
        // }
        // return {};

        // ================================
        // Approach 3: Find element
        // - Time  Complexity: O(N²)
        //   (std::find takes O(N), we do it N times)
        // - Space Complexity: O(1)
        //   (No extra space used)
        // - Pros: Intuitive
        // - Cons: Time Limit exceeds 
        // ================================
        int n = numbers.size();
        int complement = 0;

        for (int i = 0; i < n - 1; i++)
        {
            int complement = target - numbers[i];
    // i+1 부터 끝까지 중 complement 이상의 값이 처음 나오는 위치 탐색
    auto it = lower_bound(numbers.begin() + i + 1, numbers.end(), complement);
    
    if (it != numbers.end() && *it == complement) {
        return { i + 1, static_cast<int>(it - numbers.begin()) + 1 };
    }
        }
        return {};
    }
};