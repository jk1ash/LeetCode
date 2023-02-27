/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        vector<int> ans(n, 0);
        for (auto& num : nums) {
            if (num % 2 == 0)
                ans[l++] = num;
            else
                ans[r--] = num;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums{3,1,2,4}, ans;
    ans = s.sortArrayByParity(nums);
    cout << "[";
    for (auto& a : ans)
        cout << a <<  ",";
    cout << "\b \b]" << endl;
    return 0;
}
