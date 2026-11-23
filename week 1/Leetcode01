
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size,
                        int* returnSize) {
    int i, j, k;
    int* result;
    result = (int*)malloc(nums1Size * sizeof(int));
    *returnSize = nums1Size;

    for (i = 0; i < nums1Size; i++) {
        result[i] = -1;

        for (j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) {
                for (k = j + 1; k < nums2Size; k++) {
                    if (nums2[k] > nums1[i]) {
                        result[i] = nums2[k];
                        break;
                    }
                }

                break;
            }
        }
    }

    return result;
}
