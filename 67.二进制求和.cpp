/*
 * @Author: jklash
 * @Description: 二进制求和
 * @Date: 2021-11-17 19:30:19
 * @LastEditors: jklash
 * @LastEditTime: 2021-11-18 16:15:10
 */
/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */
#include <iostream>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
       int i = a.size() -1;
       int j = b.size() -1;
       int carry = 0;
       string ans;
    // 从底部循环相加相同长度部分
       while (i >= 0 && j >= 0) {
           int sum = carry;
           sum += a[i--] - '0';
           sum += b[j--] - '0';
           carry = sum / 2;
           ans.push_back(sum % 2 + '0');
       }
    // 若a比较长，则加上a的剩下部分   
       while (i >= 0)
       {
           int sum = carry + a[i--] - '0';
           carry = sum / 2;
           ans.push_back(sum % 2 + '0');
       }
    //  同上
       while (j >= 0)
       {
           int sum = carry + b[j--] - '0';
           carry = sum / 2;
           ans.push_back(sum % 2 + '0' );
       }
    
    //  若还有进位，加上进位
       if (carry == 1) {
           ans.push_back(carry + '0');
       }
    
    // 反转
       reverse(ans.begin(), ans.end());
       return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    string a = "11";
    string b = "1";
    cout << s.addBinary(a, b) << endl;
    return 0;
}
