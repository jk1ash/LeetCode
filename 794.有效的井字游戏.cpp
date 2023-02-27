/*
 * @Author: jklash
 * @Description: 有效的井字游戏
 * @Date: 2021-12-09 09:44:18
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-09 10:31:15
 */
/*
 * @lc app=leetcode.cn id=794 lang=cpp
 *
 * [794] 有效的井字游戏
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
private:
    // 判断获胜
    bool check (vector<vector<char>>& cs, char c) {
        // 判断行列
        for (int i = 0; i < 3; ++i) {
            if(cs[0][i] == c && cs[1][i] == c && cs[2][i] == c) return true;
            if(cs[i][0] == c && cs[i][1] == c && cs[i][2] == c) return true;
        }
        // 判断对角线
        bool a = cs[0][0] == c && cs[1][1] == c && cs[2][2] == c;
        bool b = cs[2][0] == c && cs[1][1] == c && cs[0][2] == c;
        return a || b;
    }

public:
    bool validTicTacToe(vector<string>& board) {
        vector<vector<char>> cs (3, vector<char> (3));
        int xcnt = 0, ocnt = 0;
        // 计数
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                char c = board[i][j];
                if (c == 'X') xcnt++;
                if (c == 'O') ocnt++;
                cs[i][j] = c;
            }
        }
        
        // 由于X先手, 所以X数量大等于O, 且两者相差应不大于1
        if (ocnt > xcnt || xcnt - ocnt > 1) return false;

        bool x = check(cs, 'X'), o = check(cs, 'O');
        if (x && xcnt <= ocnt) return false; // X赢, 但是O大等X
        if (o && xcnt != ocnt) return false; // O赢, 但是X和O数量不一致
        if (x && o) return false; //两个都赢
        return true;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> board {"XXX","   ","OOO"};
    cout << s.validTicTacToe(board) << endl; 
    return 0;
}
