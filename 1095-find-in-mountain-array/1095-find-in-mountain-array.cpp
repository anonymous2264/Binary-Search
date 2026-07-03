/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        // Step 1: Find peak index
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        int peak = left;

        // Step 2: Binary search ascending half [0, peak]
        left = 0;
        right = peak;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = mountainArr.get(mid);
            if (val == target) {
                return mid;
            } else if (val < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Step 3: Binary search descending half [peak, n-1]
        left = peak;
        right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = mountainArr.get(mid);
            if (val == target) {
                return mid;
            } else if (val > target) {
                // Descending: larger values are on the left, go right
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};