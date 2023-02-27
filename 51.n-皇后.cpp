/*
 * @Author: jklash
 * @Description: N 皇后
 * @Date: 2021-11-11 17:52:03
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-19 17:41:17
 */
/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<string>> ans;

    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        vector<string> board(n, string(n, '.'));
        backtacing(n, 0, board);
        return ans;
    }

    void backtacing(int n, int row, vector<string>& board) {
        if (row == n) {
            ans.push_back(board);
            return ;
        }
        for(int col = 0; col < n; ++col) {
            // 检查是否符合条件
            if (isValid(n, row, col, board)) {
                board[row][col] = 'Q'; // 放置皇后
                backtacing(n, row + 1, board);
                board[row][col] = '.'; // 回溯, 撤销皇后
            }
        }
    }

    bool isValid(int n, int row, int col, vector<string>& board) {       
        // 检查列
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q')
                return false;
        }

        // 检查正对角线
        for (int i = row - 1, j = col - 1; 
            i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q')
                return false;
        }

        // 检查反对角线
        for (int i = row -1, j = col + 1; 
            i >= 0 && j < n; --i, ++j) {
                if (board[i][j] == 'Q')
                    return false;
        }
        
        return true;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<string>> res = s.solveNQueens(4);
    for (auto& r : res) {
        for (auto& v : r) {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}
