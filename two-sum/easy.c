#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Comparator function for qsort to sort indices based on values in nums array
int compare(const void* a, const void* b, void* nums) {
    int idx1 = *(int*)a;
    int idx2 = *(int*)b;
    return ((int*)nums)[idx1] - ((int*)nums)[idx2];
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Create an array of indices
    int* indices = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        indices[i] = i;
    }

    // Sort the indices array based on the values in nums
    qsort_r(indices, numsSize, sizeof(int), compare, nums);

    // Two-pointer approach to find the target sum
    int* result = (int*)malloc(2 * sizeof(int));
    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int sum = nums[indices[left]] + nums[indices[right]];
        if (sum == target) {
            // If the target sum is found, store the original indices in result
            result[0] = indices[left];
            result[1] = indices[right];
            *returnSize = 2;
            free(indices); // Free the memory allocated for indices
            return result;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    // If no solution is found
    free(indices);
    *returnSize = 0;
    free(result);
    return NULL;
}
