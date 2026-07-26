class Solution {
public:
    bool isPalindrome(int x) {
        // Special cases: negative numbers or numbers ending with 0 (except 0)
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedNum = 0;
        while (x > reversedNum) {
            reversedNum = reversedNum * 10 + x % 10;
            x /= 10;
        }

        // When the length is an odd number, we can get rid of the middle digit by reversedNum / 10
        return x == reversedNum || x == reversedNum / 10;
    }
};