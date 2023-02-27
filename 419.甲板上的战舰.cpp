/*
 * @Author: jklash
 * @Description: 甲板上的战舰
 * @Date: 2021-12-18 09:41:55
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-18 11:00:40
 */
/*
 * @lc app=leetcode.cn id=419 lang=cpp
 *
 * [419] 甲板上的战舰
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/* 
    方法1: 一次扫描 + O(1);
 */
#if 0
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size(), ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0 && board[i - 1][j] == 'X') continue;
                if (j > 0 && board[i][j - 1] == 'X') continue;
                if (board[i][j] == 'X') ans++;
            }
        }
        return ans;
    }
};
#endif

/* 
    方法2: 二次扫描
 */

#if 0 
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size(), ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] != 'X')
                    continue;
                
                board[i][j] = '-';
                
                for (int k = i + 1; k < m && board[k][j] == 'X'; ++k)
                    board[k][j] = '-';
                
                for (int k = j + 1; k < n && board[i][k] == 'X'; ++k)
                    board[i][k] = '-';
                
                ans++;
            }
        }

        // 还原 board 
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '-')
                    board[i][j] == 'X';
            }
        }
        return ans;
    }
};
#endif

/* 
    方法3: 辅助数组
 */
// @lc code=start
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size(), ans = 0;
        vector<vector<bool>> v (m, vector<bool>(n, false)) ;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] != 'X' || v[i][j]) 
                    continue;
                
                v[i][j] = true;
                
                for (int k = i + 1; k < m && board[k][j] == 'X'; ++k)
                    v[k][j] = true;
                
                for (int k = j + 1; k < n && board[i][k] == 'X'; ++k)
                    v[i][k] = true;
                
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<char>> b {{'X','.','.','X'}, {'.','.','.','X'}, {'.','.','.','X'}};
    cout << s.countBattleships(b) << endl;
    return 0;
}
