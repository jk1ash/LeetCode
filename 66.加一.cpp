#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >=0; --i) {
            ++digits[i];
            digits[i] %= 10;
            if (digits[i] != 0)
                return digits;
        }
        vector<int> ans(n+1);
        ans[0] = 1;
        return ans;
    }
};
// @lc code=end

