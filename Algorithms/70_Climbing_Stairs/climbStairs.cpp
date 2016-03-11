class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) return 1;
        int p = 1;  //f(0)
        int q = 1;  //f(1)
        int result = 0;
        // f(n) = f(n-2) + f(n-1) ; n>=2
        for (int i = 2; i <= n; ++i) {
            result = p + q;
            p = q;
            q = result;
        }
        return result;
    }
};