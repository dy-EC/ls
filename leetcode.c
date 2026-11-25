#include<stdio.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize);

int main() {
    int nums[] = {1,3};
    int target = 1;
    int returnSize[2]={0};
    int len=sizeof(nums)/sizeof(int);
    int * arr=searchRange(nums,len,target,returnSize);
    printf("%d %d \n",arr[0],arr[1]);
    free(arr);
    return 0;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int left=0,right=numsSize-1;
    *returnSize=2;
    int *arr=(int *)malloc(2*sizeof(int));
    if (!numsSize) {
        arr[0] = -1;
        arr[1] = -1;
        return arr;
    }
    if(numsSize==1)
    {
        if(target==nums[0])
        {
            arr[0] = 0;
            arr[1] = 0;
            return arr;
            
        }else{
            arr[0] = -1;
            arr[1] = -1;
            return arr;
        }
    }
    while(left<=right)
    {
        int n=(left+right)/2;
        if(nums[n]>target)
        {
            right=n-1;
        }else
        {
            left=n+1;
        }
    }
    if(right<0||left==numsSize)
    {
        if(!((right==numsSize-1&&nums[right]==target)||(left==0&&nums[left]==target)))
        {
        arr[0]=-1;
        arr[1]=-1;
        return arr;
        }
    }
    int R=right;

    left=0,right=numsSize-1;
    while(left<=right)
    {
        int n=(left+right)/2;
        if(nums[n]<target)
        {
            left=n+1;
        }else
        {
            right=n-1;
        }
    }
    int L=left;
    if(nums[L]==target&&nums[R]==target)
    {
        arr[0]=L;
        arr[1]=R;
        return arr;
    }
    else
    {
        arr[0] = -1;
        arr[1] = -1;
        return arr;
    }
}