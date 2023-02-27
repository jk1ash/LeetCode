/*
 * @Author: jklash
 * @Description: 供暖器
 * @Date: 2021-12-20 09:52:29
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-20 10:33:48
 */
/*
 * @lc app=leetcode.cn id=475 lang=cpp
 *
 * [475] 供暖器
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
private:
    // 验证函数
    bool check(vector<int>& houses, vector<int>& heaters, int x) {
        int m = houses.size(), n = heaters.size();
        for (int i = 0, j = 0; i < m; ++i) {
            while (j < n && houses[i] > heaters[j] + x) 
                j++;
            // 如果当前houses能被覆盖, 跳出循环, 验证下一个
            if (j < n && houses[i] >= heaters[j] - x && houses[i] <= heaters[j] + x)
                continue;
            return false;
        }
        return true;
    }
    
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int l = 0, r = (int) 1e9;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (check(houses, heaters, m))
                r = m;
            else
                l = m + 1;
        }
        return r;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> houses {1,2,3,4};
    vector<int> heaters {1,4};
    cout << s.findRadius(houses, heaters) << endl;
    return 0;
}
