/*
 * @Author: jklash
 * @Description: 边框着色
 * @Date: 2021-12-07 10:43:42
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-07 14:26:58
 */
/*
 * @lc app=leetcode.cn id=1034 lang=cpp
 *
 * [1034] 边框着色
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
using namespace std;

/* 
    方法1： BFS
 */
// @lc code=start
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans (m, vector<int> (n));
        vector<vector<int>> dirs {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        deque<vector<int>> d;
        d.push_back({row, col});

        // 填充颜色
        while (!d.empty()) {
            vector<int> front = d.front();
            d.pop_front();
            int x = front[0], y = front[1], cnt = 0;
            for (auto& dir : dirs) {
                int nx = x + dir[0], ny = y + dir[1];
                
                if (nx < 0 || nx >=m || ny < 0 || ny >= n) 
                    continue;
                
                if (grid[x][y] != grid[nx][ny]) {
                    continue;
                } 
                else {
                    cnt++;
                }

                if (ans[nx][ny] != 0) 
                    continue;
                
                d.push_back({nx, ny});
            }
            ans[x][y] = cnt == 4 ? grid[x][y] : color;
        }

        // 将剩余的空格填充
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (ans[i][j] == 0)
                    ans[i][j] = grid[i][j];
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> ret;
    vector<vector<int>> grid {{1,1,1}, {1,1,1}, {1, 1, 1}};
    int row = 1, col = 1, color = 2;
    ret = s.colorBorder(grid, row, col, color);
    cout << "[";
    for (auto& r : ret) {
        cout << "[";
        for (auto& c : r) {
            cout << c << ",";
        }
        cout << "\b \b" << "]";
    }
    cout << "]" << endl;
    return 0;
}
