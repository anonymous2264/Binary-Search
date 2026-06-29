/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
             int low = 1;
        int high = n;

        while (low <= high) {
            // Avoid overflow: don't use (low + high) / 2
            int mid = low + (high - low) / 2;
            int result = guess(mid);

            if (result == 0) {
                return mid;        // Found the number
            } else if (result == -1) {
                high = mid - 1;    // Pick is lower, search left half
            } else {
                low = mid + 1;     // Pick is higher, search right half
            }
        }
        return -1;
    }
};