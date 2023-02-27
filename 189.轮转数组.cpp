/*
 * @Author: jklash
 * @Description: 轮转数组
 * @Date: 2021-11-29 14:40:48
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-30 09:55:19
 */
/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums, 0, n - 1); // 7654321
        reverse(nums, 0, k - 1); // 5674321
        reverse(nums, k, n - 1); // 5671234
    }

    void reverse(vector<int>& nums, int left, int right) {
        while (left < right) {
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            left++;
            right--;
        }
    }

};
// @lc code=end

void vector_print(vector<int>& vec) {
    for (auto v : vec) {
        cout << v << ","; 
    }
    cout << "\b \b" <<endl;
}

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> vec {-1};
    int k = 2;
    vector_print(vec);
    s.rotate(vec, k);
    vector_print(vec);
    return 0;
}
