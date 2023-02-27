/*
 * @Author: jklash
 * @Description: 寻找旋转排序数组中的最小值
 * @Date: 2021-12-03 16:47:55
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-06 22:08:43
 */
/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] < nums[high]) {
                high = mid;
            } else {
                low = mid  + 1;
            }
        }
        return nums[low];
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums {3,4,5,1,2};
    cout << s.findMin(nums) << endl;
    return 0;
}