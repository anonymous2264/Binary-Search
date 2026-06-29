class Solution {
public:
    bool isPerfectSquare(int num) {
        // Newton's method: start with num, converge toward sqrt(num)
        long long x = num;
        while (x * x > num) {
            x = (x + num / x) / 2;
        }
        return x * x == num;
    }
};