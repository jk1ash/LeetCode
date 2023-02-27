/*
 * @Author: jklash
 * @Description: 剑指 Offer 04. 二维数组中的查找
 * @Date: 2021-12-02 16:02:05
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-02 16:49:30
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/*
    方法1: 暴力法
 */
#if 0
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        for (auto& row: matrix) {
            for (auto elem: row) {
                if (elem == target) {
                    return true;
                }
            }
        }
        return false;
    }
};
#endif

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;

        int n = matrix.size(), m = matrix[0].size();
        int row = 0, col = m -1;
        while (row < n && col >= 0) {
            int num = matrix[row][col];
            if (num == target) {
                return true;
            } else if (num > target) {
                col--;
            } else {
                row++;
            }
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> matrix {{1, 4,  7, 11, 15},
                            {2,   5,  8, 12, 19}, 
                            {3,   6,  9, 16, 22},
                            {10, 13, 14, 17, 24},
                            {18, 21, 23, 26, 30}};
    // vector<vector<int>> matrix {};
    int target = 5;
    cout << s.findNumberIn2DArray(matrix, target) << endl;
    return 0;
}
