/*
 * @lc app=leetcode.cn id=29 lang=java
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
    public int divide(int dividend, int divisor) {
        if (dividend == Integer.MIN_VALUE) {
            if (divisor == 1) {
                return Integer.MIN_VALUE;
            } else if (divisor == -1) {
                return Integer.MAX_VALUE;
            }
        }
        if (divisor == Integer.MIN_VALUE) {
            return dividend == Integer.MIN_VALUE ? 1 : 0;
        }
        if (divisor == 0) {
            return 0;
        }

        boolean rev = false;
        if (dividend > 0) {
            dividend = -dividend;
            rev = !rev;
        }
        if (divisor > 0) {
            divisor = -divisor;
            rev = !rev;
        }

        int left = 1, right = Integer.MAX_VALUE, ans = 0;
        while(left <= right) {
            int mid = left + ((right - left) >> 1);
            boolean check = quickAdd(divisor, mid, dividend);
            if (check) {
                ans = mid;
                if (mid == Integer.MAX_VALUE) {
                    break;
                }
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return rev ? -ans : ans;
    }

    public boolean quickAdd(int y, int z, int x) {
        int res = 0, add = y;
        while(z != 0) {
            if((z & 1) != 0) {
                if (res < x - add) {
                    return false;
                }
                res += add;
            }
            if (z != 1) {
                if (add < x - add) {
                    return false;
                }
                add += add;
            }
            z >>= 1;
        }
        return true;
    }
}
// @lc code=end

