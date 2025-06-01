#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Ensure nums1 is the smaller array, for simplicity in binary search
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int x = nums1Size;
    int y = nums2Size;
    int low = 0, high = x;

    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        // Edge cases where partition is at the beginning or end
        int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];

        int minX = (partitionX == x) ? INT_MAX : nums1[partitionX];
        int minY = (partitionY == y) ? INT_MAX : nums2[partitionY];

        if (maxX <= minY && maxY <= minX) {
            // Found the correct partition
            if ((x + y) % 2 == 0) {
                return ((double)fmax(maxX, maxY) + fmin(minX, minY)) / 2;
            } else {
                return (double)fmax(maxX, maxY);
            }
        } else if (maxX > minY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }

    // If the input is not valid
    return -1.0;
}
