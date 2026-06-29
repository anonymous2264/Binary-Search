class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();

        while (left < right) {
            // Avoids overflow compared to (left + right) / 2
            int mid = left + (right - left) / 2;

            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                // nums[mid] >= target, so mid is a candidate
                right = mid;
            }
        }

        return left;
    }
};