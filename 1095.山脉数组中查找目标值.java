/*
 * @lc app=leetcode.cn id=1095 lang=java
 *
 * [1095] 山脉数组中查找目标值
 */

// @lc code=start
/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */
 
class Solution {
    public int findInMountainArray(int target, MountainArray mountainArr) {
        int len =  mountainArr.length();
        int left = 0, right = len - 1;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (mountainArr.get(mid) < mountainArr.get(mid+1))
                left = mid + 1;
            else
                right = mid;
        }
        int top = right;
        int ans = findTopLeft(target, mountainArr, 0, top);
        if (ans != -1) {
            return ans;
        }
        return findTopRight(target, mountainArr, top + 1, len - 1);

    }

    public int findTopLeft(int target, MountainArray mountainArr, int left, int right) {
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (mountainArr.get(mid) < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (mountainArr.get(right) == target) {
            return right;
        }
        return -1;
    }

    public int findTopRight(int target, MountainArray mountainArr, int left, int right) {
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (mountainArr.get(mid) > target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (mountainArr.get(right) == target) {
            return right;
        }
        return -1;
    }
}
// @lc code=end

