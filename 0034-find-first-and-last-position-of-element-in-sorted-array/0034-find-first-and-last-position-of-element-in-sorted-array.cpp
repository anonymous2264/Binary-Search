class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lowerBound(nums, target);

        // Check if target exists
        if (first == nums.size() || nums[first] != target) {
            return {-1, -1};
        }

        int last = upperBound(nums, target) - 1;
        return {first, last};
    }

private:
    // Finds the first index where nums[i] >= target
    int lowerBound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    // Finds the first index where nums[i] > target
    int upperBound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};