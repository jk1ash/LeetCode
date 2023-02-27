class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int len = arr.length;
        int left = 1, right = len - 1;
        while(left < right) {
            int mid = left + right + 1 >> 1;
            if (arr[mid -1] < arr[mid])
                left = mid;
            else
                right = mid - 1;
        }
        return right;
    }
}
