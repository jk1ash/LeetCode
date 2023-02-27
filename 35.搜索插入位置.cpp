/*
 * @Author: jklash
 * @Description: 搜索插入位置
 * @Date: 2021-12-06 22:19:20
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-06 22:41:43
 */
/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       int low = 0, high = nums.size() - 1;
       while (low <= high) {
           int mid = low + ((high - low) >> 1);
           if (nums[mid] < target) {
               low = mid + 1;
           } else {
               high = mid - 1; 
           }
        }
        return low;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums {1,3,5,6};
    int target = 3;
    cout << s.searchInsert(nums, target) << endl;
    return 0;
}

