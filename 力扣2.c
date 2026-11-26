int search(int* nums, int numsSize, int target) {
    // int tip=-1;
    int left = 0;
    int right = numsSize - 1;
    while (left <= right) {
        int n = left + (right - left) / 2;
        if (nums[n] < target) {
            left = n + 1;
        } else {
            right = n - 1;
        }
    }
    if (left >= numsSize)
        return -1;
    if (nums[left] == target) {
        return left;
    }
    return -1;
}