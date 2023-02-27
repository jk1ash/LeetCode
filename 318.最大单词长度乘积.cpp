/*
 * @Author: jklash
 * @Description: 最大单词长度乘积
 * @Date: 2021-11-17 11:39:31
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-17 16:18:22
 */
/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> map;
        int n = words.size(), idx = 0;

        // 将每个单词存到hash表中
        for (auto& w : words) {
            int t = 0;
            int m = w.size();
            for(int i = 0; i < m; ++i) {
                t |= (1 << (w[i] - 'a'));
            }
            if (map.count(t)) {
                if(map[t] < m) 
                    map[t] = m;
            } else {
                map[t] = m;
            }
        }

        int ans = 0;
        for (auto [a, _] : map) {
            int w1 = map[a];
            for (auto [b, _] : map) {
                if ((a & b) == 0) { // 如果位掩码不同, 这说明单词没有重复字母, 进行计算
                    int w2 = map[b];
                    ans = max(ans, w1 * w2);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> t = {"bdcecbcadca","caafd","bcadc","eaedfcd","fcdecf","dee","bfedd","ffafd","eceaffa","caabe","fbdb","acafbccaa","cdc","ecfdebaafde","cddbabf","adc","cccce","cbbe","beedf","fafbfdcb","ceecfabedbd","aadbedeaf","cffdcfde","fbbdfdccce","ccada","fb","fa","ec","dddafded","accdda","acaad","ba","dabe","cdfcaa","caadfedd","dcdcab","fadbabace","edfdb","dbaaffdfa","efdffceeeb","aefdf","fbadcfcc","dcaeddd","baeb","beddeed","fbfdffa","eecacbbd","fcde","fcdb","eac","aceffea","ebabfffdaab","eedbd","fdeed","aeb","fbb","ad","bcafdabfbdc","cfcdf","deadfed","acdadbdcdb","fcbdbeeb","cbeb","acbcafca","abbcbcbaef","aadcafddf","bd","edcebadec","cdcbabbdacc","adabaea","dcebf","ffacdaeaeeb","afedfcadbb","aecccdfbaff","dfcfda","febb","bfffcaa","dffdbcbeacf","cfa","eedeadfafd","fcaa","addbcad","eeaaa","af","fafc","bedbbbdfae","adfecadcabe","efffdaa","bafbcbcbe","fcafabcc","ec","dbddd","edfaeabecee","fcbedad","abcddfbc","afdafb","afe","cdad","abdffbc","dbdbebdbb"};
    cout << s.maxProduct(t) << endl;
    return 0;
}
