/*
 * @Author: jklash
 * @Description: 第 K 个最小的素数分数
 * @Date: 2021-11-29 10:21:23
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-29 14:11:03
 */
/*
 * @lc app=leetcode.cn id=786 lang=cpp
 *
 * [786] 第 K 个最小的素数分数
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
private:
    double eps = 1e-8;
    vector<int> arr;
    int n, a, b;

public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        this->arr = arr;
        n = arr.size();
        double left = 0, right = 1;
        while (right - left > eps) {
            double mid = (left + right) / 2;
            if (check(mid) >= k) 
                right = mid;
            else
                left = mid;
        }
        return {a, b};
    }

    int check(double x) {
        int ans = 0;
        for (int i = 0, j = 1; j < n; ++j) {
            while (arr[i + 1] * 1.0 / arr[j] <= x) i++;
            if (arr[i] * 1.0 / arr[j] <= x) ans += i + 1;
            if (abs(arr[i] * 1.0 / arr[j] - x) < eps) {
                a = arr[i];
                b = arr[j];
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> t {1,2,3,5};
    int k = 3;
    vector<int> ans = s.kthSmallestPrimeFraction(t, k);
    for (auto a : ans) {
        cout << a << ",";
    }
    cout << "\b \b" << endl;
    return 0;
}
