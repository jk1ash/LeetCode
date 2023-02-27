/*
 * @Author: jklash
 * @Description: 剑指 Offer 11. 旋转数组的最小数字
 * @Date: 2021-12-03 16:41:49
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-06 22:18:19
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int low = 0, high = numbers.size() - 1;
        while (low < high) {
            int mid = low + ((high - low) >> 1);
            if (numbers[mid] < numbers[high]) {
                high = mid;
            } else if (numbers[mid] > numbers[high]) {
                low = mid + 1;
            } else {
                high--;
            }
        }
        return numbers[low];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums {3,4,5,1,2};
    cout << s.minArray(nums) << endl;
    return 0;
}
