/*
 * @Author: jklash
 * @Description: 剑指 Offer 53 - I. 在排序数组中查找数字 I
 * @Date: 2021-11-26 10:55:53
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-26 14:17:22
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 二分找到目标值的右边界，减去上一个数字的右边界，得到目标值的数量
        return binarySearch(nums, target) - binarySearch(nums, target - 1);
    }

    int binarySearch(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            if (nums[m] <= target) l = m + 1; // 为了确定右边界，后面可能还有目标值
            else r = m -1;
        }
        return l;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> t {5,7,7,8,8,10};
    int target = 6;
    cout << s.search(t, target) << endl;
    return 0;
}
