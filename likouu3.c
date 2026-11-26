int searchInsert(int* nums, int numsSize, int target) {
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
    // if(left>=numsSize)
    // return numsSize;
    // if(nums[left]==target)
    // {
    return left;
    //}
}