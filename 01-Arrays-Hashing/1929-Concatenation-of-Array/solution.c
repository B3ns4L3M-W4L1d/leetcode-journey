#include <stdlib.h>

int* getConcatenation(int* nums, int numsSize, int* returnSize) 
{
    
    int *liste = malloc(sizeof(int) * (numsSize * 2));
    
    for ( int i = 0; i < numsSize; i++) {
            liste[i] = nums[i];
    }
    for ( int y = 0; y < numsSize; y++) {
            liste[y + numsSize] = nums[y];
    }

    *returnSize = numsSize * 2;

    return liste;
}