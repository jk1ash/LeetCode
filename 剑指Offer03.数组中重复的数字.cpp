/*
 * @Author: jklash
 * @Description: 剑指 Offer 03. 数组中重复的数字
 * @Date: 2021-11-25 18:06:49
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-26 10:54:12
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/* 
    方法1: 集合
*/
#if 0
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> set;
        for (int num : nums) {
            if (set.count(num)) return num;
            set.insert(num);
        }
        return -1;
    }
};
#endif

/* 
    方法2: 原地算法
*/

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == i) { // 该处的索引已等于数字
                i++;
                continue;
            }
            if (nums[nums[i]] == nums[i]) { // 如果当前数字等于索引， 说明重复， 返回答案
                return nums[i];
            }
            swap(nums[i], nums[nums[i]]); // 交换索引和数字， 让当前数字等于索引
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> t {2, 3, 1, 0, 2, 5, 3};
    cout << s.findRepeatNumber(t) << endl;
    return 0;
}
