// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
         int low = 1;
        int high = n;
        while (low < high) {
            // Avoid overflow: don't use (low + high) / 2
            int mid = low + (high - low) / 2;

            if (isBadVersion(mid)) {
                // mid could be the first bad version
                high = mid;
            } else {
                // mid is good, first bad must be after mid
                low = mid + 1;
            }
        }
        // low == high, pointing to the first bad version
        return low;
    }
};