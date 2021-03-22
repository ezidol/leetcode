

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *arr = (int *)malloc(sizeof(int) * (*returnSize));
    int i, j;
    for (i = 0; i < numsSize-1; i++) {
        for (j = 1; j < numsSize; j++) {
            if (i != j) {
                if (target == nums[i] + nums[j]) {
                    arr[0] = i;
                    arr[1] = j;
                    break;
                }    
            }
        }
    }
    
    return arr;
}
