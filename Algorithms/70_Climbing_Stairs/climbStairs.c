
// 递归版，递归深度越大越耗时，n>40时leetcode判断超时
int climbStairs(int n) {
    if (n == 0 || n == 1) return 1;
    return climbStairs(n - 1) + climbStairs(n - 2);
}

// 迭代版
int climbStairs(int n) {
    if (n == 0 || n == 1) return 1;
    int p = 1;
    int q = 1;
    int result = 0;
    for (int i = 2; i <= n ; i++) {
        result = p + q;
        p = q;
        q = result;
    }
    return result;
}