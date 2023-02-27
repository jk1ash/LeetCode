/*
 * @Author: jklash
 * @Description: 搜索旋转排序数组
 * @Date: 2021-12-10 13:59:10
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-10 14:20:42
 */
/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // 直接找到目标数字
            if (nums[mid] == target) {
                return mid; 
            // 位于左区间[left, mid]
            } else if (nums[left] <= nums[mid]) {
                if (target < nums[mid] && target >= nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            // 位于右区间[mid, right]
            } else {
                if (target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums {4,5,6,7,0,1,2};
    int target = 0;
    cout << s.search(nums, target) << endl;
    return 0;
}
