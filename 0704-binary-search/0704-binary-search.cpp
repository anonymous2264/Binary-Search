class Solution {
public:
    int search(vector<int>& nums, int target) {
         int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            // Avoids potential integer overflow compared to (left + right) / 2
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                // Target is in the right half
                left = mid + 1;
            } else {
                // Target is in the left half
                right = mid - 1;
            }
        }
        // Target not found
        return -1;
    }
};