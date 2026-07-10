# 217 - Contains Duplicate

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-00b8a3?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays%20%26%20Hashing-A78BFA?style=for-the-badge)

---

## 📋 Problem

Given an integer array `nums`, return `true` if any value appears **at least twice**, and `false` if every element is distinct.

**Example 1:**
```
Input:  nums = [1,2,3,1]
Output: true
```

**Example 2:**
```
Input:  nums = [1,2,3,4]
Output: false
```

**Example 3:**
```
Input:  nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
```

**Constraints:**
- `1 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`


---

## 🔵 Solution C

```c
#include <stdbool.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1])
            return true;
    }
    return false;
}
```

**Explanation:**
- `compare` — helper function required by `qsort` to know how to compare two elements. It takes two `void*` pointers, casts them to `int*`, and returns their difference (negative, 0, or positive = ascending sort).
- `qsort(nums, numsSize, sizeof(int), compare)` — sorts the array in place. Once sorted, all duplicates are guaranteed to be next to each other.
- Loop — iterate through the sorted array and check if `nums[i] == nums[i + 1]`. If two neighbors are equal, a duplicate exists → return `true`.
- If the loop ends without finding any equal neighbors → return `false`.

---

## 🟣 Solution C++

```cpp
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> liste;

        for (int i = 0; i < nums.size(); i++) {
            if (liste.count(nums[i])) {
                return true;
            }
            liste.insert(nums[i]);
        }
        return false;
    }
};
```

**Explanation:**
- `std::unordered_set<int> liste` — declare an empty hashset. Lookups and insertions are O(1) on average.
- `liste.count(nums[i])` — returns 1 if the element already exists in the set, 0 if not. If it exists → duplicate found → return `true`.
- `liste.insert(nums[i])` — if not found, add the element to the set and continue.
- If the loop ends without finding a duplicate → return `false`.

---

## 🟡 Solution Python

```python
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        duplicate = set()

        for i in nums:
            if i in duplicate:
                return True
            duplicate.add(i)
        return False
```

**Explanation:**
- `duplicate = set()` — declare an empty set. Same concept as `unordered_set` in C++, native in Python.
- `if i in duplicate` — check if the current element already exists in the set. If yes → return `True`.
- `duplicate.add(i)` — if not found, add it to the set and continue.
- Same logic as C++ but more concise syntax.



> Note: The C solution uses a different approach (sort + compare neighbors) because C has no native hashset.