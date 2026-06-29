class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[mid + 1]) {
                // Uphill to the right, peak must be in [mid+1, right]
                left = mid + 1;
            } else {
                // Downhill to the right, peak is at mid or to the left
                right = mid;
            }
        }

        // left == right, pointing to a peak
        return left;
    }
};