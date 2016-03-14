int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 0) return 0;
    if (numsSize == 1) return 1;
    int count = 0;
    for (int i = 1; i < numsSize; ++i) {
        if (nums[count] != nums[i]) {
            count++;
            nums[count] = nums[i];
        }
    }
    return count + 1;
}
