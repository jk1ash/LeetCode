/*
 * @Author: jklash
 * @Description: 寻找旋转排序数组中的最小值 II
 * @Date: 2021-12-03 16:46:04
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-06 22:14:56
 */
/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
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
            } else if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high--;
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
