int removeElement(int* nums, int numsSize, int val) {
    int newLength = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            newLength++;
            nums[newLength - 1] = nums[i];
        }
    }
    return newLength;
}