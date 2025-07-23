/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>

int main()
{

    return 0;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    for (size_t i = 0; i < numsSize; i++)
    {
        for (size_t y = i + 1; y < numsSize; y++)
        {
            /* code */
            if (nums[i] + nums[y] == target)
            {
                return target;
            }
        }
    }
}

// nums array, 0,1 ?= target return true.
// We need 2 for loops.
//

// y is always y + 1
// array[i] + array[y] ?= target. | y < length of array - i