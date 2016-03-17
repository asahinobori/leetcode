// stupid version
bool isPalindrome(int x) {
    if (x < 0) return false;
    int tmp = x;
    int num = tmp;
    int cnt = 1;
    while (tmp > 9) {
        cnt++;
        tmp /= 10;
    }
    int *p = (int*)malloc(cnt * sizeof(int));
    for (int i = 0; i < cnt; ++i) {
        p[i] = num % 10;
        num /= 10;
    }

    for (int i = 0; i < (cnt / 2); ++i) {
        if (p[i] != p[cnt-i-1]) {
            free(p);
            return false;
        }
    }
    free(p);
    return true;
}

// clever version
bool isPalindrome(int x) {
    if (x < 0) return false;
    int div = 1;
    while (x / div >= 10) div *= 10;
    while (x > 0) {
        int high = x / div;
        int low = x % 10;
        if (high != low) return false;
        x = x % div / 10;
        div /= 100;
    }
    return true;
}