/*
 * @Author: jklash
 * @Description: 剑指 Offer 53 - II. 0～n-1中缺失的数字
 * @Date: 2021-11-26 14:25:50
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-26 15:39:10
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/* 
    方法1：暴力法

 */
#if 0
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i)
                return i;
        }
        return n;
    }
};
#endif

/* 
    方法2： 二分法
    
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = 0, r = nums.size() -1;
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            if (nums[m] == m) l = m + 1;
            else r = m - 1;
        }
        return l;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> t {0,2};
    cout << s.missingNumber(t) << endl;
    return 0;
}
