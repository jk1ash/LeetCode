/*
 * @Author: jklash
 * @Description: 
 * @Date: 2021-10-28 10:04:36
 * @LastEditors: jklash
 * @LastEditTime: 2021-10-28 14:54:39
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=869 lang=cpp
 *
 * [869] 重新排序得到 2 的幂
 */

// @lc code=start
class Solution {
public:
    vector<int> vis;

    bool reorderedPowerOf2(int n) {
        string nums = to_string(n);
        sort(nums.begin(), nums.end());
        vis.resize(nums.size());
        return backtrace(nums, 0, 0);
    }

    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n -1)) == 0;
    }

    bool backtrace(string& nums, int idx, int num) {
        if (idx == nums.size())
            return isPowerOfTwo(num);
        
        for (int i = 0; i < nums.size(); i++) {
            if (num == 0 && nums[i] == '0' || vis[i] || (i > 0 && !vis[i - 1] && nums[i] == nums[i - 1])) {
                continue;
            }
            vis[i] = 1;
            if (backtrace(nums, idx + 1, num * 10 + nums[i] - '0')) {
                return true;
            }
            vis[i] = 0;
        }
        return false;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    int n = 16;
    cout << s.reorderedPowerOf2(n) << endl;
    return 0;
}
