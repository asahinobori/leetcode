/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    bool flag = true;
    for (int i = 0; i < digitsSize; ++i) {
        int cur = digits[digitsSize - i - 1];
        if (flag) {
            cur += 1;
        } else {
            break;
        }
        if (cur == 10) {
            cur = 0;
            flag = true;
        } else {
            flag = false;
        }
        digits[digitsSize - i - 1] = cur;
    }
    *returnSize = flag ? digitsSize + 1 : digitsSize;
    int *newDigits = (int*)malloc(*returnSize * sizeof(int));
    if (flag) {
        memset(newDigits, 0, *returnSize * sizeof(int));
        newDigits[0] = 1;
    } else {
        memcpy(newDigits, digits, digitsSize * sizeof(int));
    }
    return newDigits;
}