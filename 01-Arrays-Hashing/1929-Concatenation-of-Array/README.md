# 1929 - Concatenation of Array

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-00b8a3?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays%20%26%20Hashing-A78BFA?style=for-the-badge)

---

## 📋 Problem

Given an integer array `nums` of length `n`, create an array `ans` of length `2n` where:
- `ans[i] == nums[i]`
- `ans[i + n] == nums[i]`

for `0 <= i < n` (0-indexed). Return the array `ans`.

**Example 1:**
```
Input:  nums = [1,2,1]
Output: [1,2,1,1,2,1]
```

**Example 2:**
```
Input:  nums = [1,3,2,1]
Output: [1,3,2,1,1,3,2,1]
```

**Constraints:**
- `n == nums.length`
- `1 <= n <= 1000`
- `1 <= nums[i] <= 1000`

---

## 🔵 Solution C

```c
#include <stdlib.h>

int* getConcatenation(int* nums, int numsSize, int* returnSize) 
{
    int *liste = malloc(sizeof(int) * (numsSize * 2));
    
    for (int i = 0; i < numsSize; i++) {
        liste[i] = nums[i];
    }
    for (int y = 0; y < numsSize; y++) {
        liste[y + numsSize] = nums[y];
    }

    *returnSize = numsSize * 2;

    return liste;
}
```

**Explanation:**
- `malloc(sizeof(int) * numsSize * 2)` — allocate memory on the heap for a new array of double the original size. We use `malloc` because a local array would be destroyed when the function returns.
- First loop — copy each element of `nums` into the first half of `liste` (index `0` to `numsSize - 1`).
- Second loop — copy each element of `nums` again into the second half (index `numsSize` to `2 * numsSize - 1`).
- `*returnSize = numsSize * 2` — write the size of the returned array into the out-parameter so the caller knows how many elements to read.
- `return liste` — return the pointer to the newly allocated array.

---

## 🟣 Solution C++

```cpp
#include <vector>

class Solution {
public:
    std::vector<int> getConcatenation(std::vector<int>& nums) {
        std::vector<int> liste;

        for (int i = 0; i < nums.size(); i++) {
            liste.push_back(nums[i]);
        }
        for (int y = 0; y < nums.size(); y++) {
            liste.push_back(nums[y]);
        }
        return liste;
    }
};
```

**Explanation:**
- `std::vector<int> liste` — declare an empty dynamic array. Unlike C, a vector manages its own memory automatically, no need for `malloc`.
- First loop — push each element of `nums` into `liste` (first half).
- Second loop — push each element of `nums` again (second half).
- `return liste` — return the vector directly by value. C++ handles memory for us.

---

## 🟡 Solution Python

```python
class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        ans = nums + nums
        return ans
```

**Explanation:**
- `nums + nums` — in Python, the `+` operator on lists creates a new list by concatenating both. This is the most concise way to solve this problem.
- `return ans` — return the concatenated list.

---