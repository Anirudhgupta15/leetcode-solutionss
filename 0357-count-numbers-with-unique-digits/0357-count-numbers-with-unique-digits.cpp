class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;  
        int total = 10;          
        int ans = 9;  
        int ava = 9; 
        for (int i = 2; i <= n && ava > 0; ++i) {
            ans *= ava;
            total += ans;
            ava--;
        }
        return total;
    }
};