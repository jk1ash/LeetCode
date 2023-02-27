/*
 * @Author: jklash
 * @Description: 
 * @Date: 2021-11-01 10:50:33
 * @LastEditTime: 2021-11-01 11:51:23
 */
/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] 分糖果
 */
#include <iostream>
#include <unordered_set>   
#include <vector>
#include <math.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        return min(unordered_set<int>(candyType.begin(), candyType.end()).size(), candyType.size() / 2);        
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> test{1,1,2,2,3,3};
    cout << s.distributeCandies(test);
    cout << endl;
    return 0;
}
