class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = left + (right - left) / 2;

            // Check if Koko can finish at speed mid
            long long totalHours = 0;
            for (int pile : piles) {
                totalHours += (pile + mid - 1) / mid;
            }

            if (totalHours <= h) {
                // Feasible, but maybe a slower speed works too
                right = mid;
            } else {
                // Too slow, need a faster speed
                left = mid + 1;
            }
        }

        return left;
    }
};