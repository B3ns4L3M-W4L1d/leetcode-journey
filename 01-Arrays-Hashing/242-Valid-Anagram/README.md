# 242 - Valid Anagram

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-00b8a3?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays%20%26%20Hashing-A78BFA?style=for-the-badge)

---

## 📋 Problem

Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise.

An anagram is a word formed by rearranging the letters of another word, using all original letters exactly once.

**Example 1:**
```
Input:  s = "anagram", t = "nagaram"
Output: true
```

**Example 2:**
```
Input:  s = "rat", t = "car"
Output: false
```

**Constraints:**
- `1 <= s.length, t.length <= 5 * 10^4`
- `s` and `t` consist of lowercase English letters

---

## 🔵 Solution C

```c
#include <stdbool.h>

bool isAnagram(char* s, char* t) {
    if (strlen(s) != strlen(t))
        return false;

    int alphabet[26] = {0};

    for (int i = 0; i < strlen(s); i++) {
        int index = s[i] - 'a';
        alphabet[index]++;
    }
    for (int i = 0; i < strlen(t); i++) {
        int index = t[i] - 'a';
        alphabet[index]--;
    }
    for (int i = 0; i < 26; i++) {
        if (alphabet[i] != 0)
            return false;
    }
    return true;
}
```

**Explanation:**
- First check if `s` and `t` have the same length — if not, they can't be anagrams, return `false` immediately.
- `int alphabet[26] = {0}` — declare an array of 26 integers (one per letter a-z), all initialized to 0.
- `s[i] - 'a'` — converts a character to its index in the alphabet (e.g. `'a'` → 0, `'b'` → 1, `'z'` → 25).
- First loop — increment the counter for each letter in `s`.
- Second loop — decrement the counter for each letter in `t`.
- Third loop — if all counters are 0, both strings used the exact same letters the same number of times → return `true`. If any counter is not 0 → return `false`.

---

## 🟣 Solution C++

```cpp
#include <string>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        int alphabet[26] = {0};

        for (int i = 0; i < s.size(); i++) {
            int index = s[i] - 'a';
            alphabet[index]++;
        }
        for (int i = 0; i < t.size(); i++) {
            int index = t[i] - 'a';
            alphabet[index]--;
        }
        for (int i = 0; i < 26; i++) {
            if (alphabet[i] != 0)
                return false;
        }
        return true;
    }
};
```

**Explanation:**
- Same logic as the C solution. The only difference is using `s.size()` instead of `strlen()` since C++ strings have a built-in `.size()` method.

---

## 🟡 Solution Python

```python
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)
```

**Explanation:**
- `sorted(s)` returns a list of characters from `s` sorted alphabetically. Same for `t`.
- If both strings are anagrams, sorting them produces the exact same list → return `True`.
- If not → return `False`.
- This is the most concise approach in Python, but less efficient than the alphabet array method since sorting is O(n log n) vs O(n).

---
