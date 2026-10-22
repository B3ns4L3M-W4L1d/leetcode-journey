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

## 🟨 Solution JavaScript

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var getConcatenation = function(nums) {

    const array = [];
    let n = nums.length;

    for (let i = 0; i < n; i++){
        array[i] = nums[i];
    }
    for (let i = 0; i < n; i++){
        array[i + n] = nums[i];
    }

    return array;
};
```

**Explanation:**
- `const array = []` — create an empty array. In JS, writing at an index beyond the current length simply grows the array, so no pre-allocation is needed.
- `let n = nums.length` — store the length **once** before the loops. Using `array.length` inside the second loop would be a bug, because it changes every time we write to `array`.
- First loop — copy each element into the first half (`array[i]`).
- Second loop — copy each element again, shifted by `n` (`array[i + n]`), to fill the second half.
- Careful with typos like `nums.lenght`: JS does not throw an error, it returns `undefined`, so the loop silently never runs.

---

## 🔷 Solution TypeScript

```typescript
function getConcatenation(nums: number[]): number[] {

    const array: number[] = [];

    let n = nums.length;

    for (let i = 0; i < n; i++){
        array[i] = nums[i];
    }
    for (let i = 0; i < n; i++){
        array[i + n] = nums[i];
    }

    return array;

};
```

**Explanation:**
- Same logic as the JavaScript version, with explicit types: `nums: number[]` for the input and `: number[]` for the return value.
- `const array: number[] = []` — typed empty array. TypeScript would reject any value that is not a number.
- The typing catches mistakes at compile time: a typo like `nums.lenght` is reported immediately ("Property does not exist on type `number[]`") instead of failing silently like in JS.

---

## 🦀 Solution Rust

```rust
impl Solution {
    pub fn get_concatenation(nums: Vec<i32>) -> Vec<i32> {
        let mut numbers: Vec<i32> = vec![];
        let n = nums.len();

        for i in 0..n {
            numbers.push(nums[i])
        }
        for i in 0..n {
            numbers.push(nums[i])
        }
        numbers
    }
}
```

**Explanation:**
- `let mut numbers: Vec<i32> = vec![]` — a growable vector. `mut` is required because we modify it with `push`.
- `nums.len()` — in Rust `len` is a **method** (with parentheses), and it returns a `usize`, the type used for indexes.
- `push` instead of `numbers[i] = ...` — indexing a `Vec` never grows it: writing at an index that does not exist makes the program panic. `push` appends at the end, so the second loop naturally fills the second half, with no `i + n` needed.
- `for i in 0..n` — the range is exclusive on the right (`0` to `n - 1`).
- `numbers` on the last line, **without a semicolon** — in Rust, the last expression of a function is its return value.

---

## ⏱️ Complexity

| | Time | Space |
|---|---|---|
| All solutions | O(n) | O(n) |

We visit each element twice (O(n)) and build a new array of size `2n` (O(n) extra space).
