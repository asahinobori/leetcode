/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

//Recursive implement cost huge !!

// int* getRow(int rowIndex, int* returnSize) {
//     if (rowIndex == 0) return NULL;
//     int* ptRow = (int*)malloc(rowIndex * sizeof(int))
//     if (rowIndex == 1) {
//         *ptRow = 1;
//         *returnSize = 1;
//         return ptRow;
//     }
//     ptRowUp = getRow(rowIndex - 1, returnSize);
//     for (int i = 1; i < rowIndex - 1; i++) {
//         *(ptRow + i) = *(ptRowUp + i - 1) + *(ptRowUp + i);
//     }
//     *ptRow = 1;
//     *(ptRow + rowIndex - 1) = 1;
//     free(ptRowUp);
//     *returnSize = rowIndex;
//     return ptRow;
// }

int* getRow(int rowIndex, int* returnSize) {
    int* pt = (int*)malloc((rowIndex+1) * sizeof(int));
    if (rowIndex == 0) {
        *pt = 1;
        *returnSize = 1;
        return pt;
    }
    int* pt_tmp = (int*)malloc((rowIndex+1) * sizeof(int));
    *pt = 1;
    for (int row = 1; row <= rowIndex; row++) {
        for (int col = 1; col < row; col++) {
            *(pt_tmp + col) = *(pt + col - 1) + *(pt + col);
        }
        *pt_tmp = 1;
        *(pt_tmp + row) = 1;
        int *exchange = pt;
        pt = pt_tmp;
        pt_tmp = exchange;
    }
    *returnSize = rowIndex + 1;
    return pt;
}