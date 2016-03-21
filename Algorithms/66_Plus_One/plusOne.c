/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int c = 1; //carry
    *returnSize = digitsSize;
    for (int i = 0; i < digitsSize; ++i) {
        digits[digitsSize - i - 1] += c;
        c = digits[digitsSize - i - 1] / 10;
        digits[digitsSize - i - 1] %= 10;
    }
    if (c > 0) {
        (*returnSize)++;
        int *newDigits = (int*)malloc(*returnSize * sizeof(int));
        newDigits[0] = 1;
        memcpy(newDigits + 1, digits, digitsSize * sizeof(int));
        return newDigits;
    } else {
        return digits;
    }
}