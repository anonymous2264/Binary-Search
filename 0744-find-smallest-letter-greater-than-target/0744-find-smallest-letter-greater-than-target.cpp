class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
           int left = 0, right = letters.size() - 1;
        int result = 0; // Default to index 0 for wrap-around
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (letters[mid] > target) {
                // This could be the answer, but check left half for smaller
                result = mid;
                right = mid - 1;
            } else {
                // letters[mid] <= target, search right half
                left = mid + 1;
            }
        }
        return letters[result];
    }
};