/*
 * @lc app=leetcode.cn id=468 lang=cpp
 *
 * [468] 验证IP地址
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    string validIPAddress(string queryIP) {
        if(checkIPv4(queryIP))
            return "IPv4";
        else if (checkIPv6(queryIP))
            return "IPv6";
        else
            return "Neither";
    }

    bool checkIPv4(string ip) {
        int n = ip.size(), cnt = 0;
        string cs = ip;
        for (int i = 0; i < n && cnt <= 3;) {
            int j = i, x = 0;
            while (j < n && cs[j] >= '0' && cs[j] <= '9' && x <= 255)
                x = x * 10 + (cs[j++] - '0');
            if (i == j)
                return false;
            if ((j - i) > 1 && cs[i] == '0' || x > 255)
                return false;
            i = j + 1;
            if (j == n)
                continue;
            if (cs[j] != '.')
                return false;
            cnt++;
        }
        return cnt == 3 && cs[0] != '.' && cs[n - 1] != '.';
    }

    bool checkIPv6(string ip) {
        int n = ip.size(), cnt = 0;
        string cs = ip;
        for (int i = 0; i < n && cnt <= 7;) {
            int j = i;
            while (j < n && 
                   ((cs[j] >= 'a' && cs[j] <= 'f') || 
                   (cs[j] >= 'A' && cs[j] <= 'F') || 
                   (cs[j] >= '0' && cs[j] <= '9'))) {
                j++;
            }
            if (i == j || j - i > 4)
                return false;
            i = j + 1;
            if (j == n)
                continue;
            if (cs[j] != ':')
                return false;
            cnt++;  
        }
        return cnt == 7 && cs[0] != ':' && cs[n - 1] != ':';
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    string ip1 = "172.16.254.1", 
           ip2 = "2001:0db8:85a3:0:0:8A2E:0370:7334", 
           ip3 = "256.256.256.256";
    cout << "ip1:" << s.validIPAddress(ip1) << endl;
    cout << "ip2:" << s.validIPAddress(ip2) << endl;
    cout << "ip3:" << s.validIPAddress(ip3) << endl;    
    return 0;
}

