# 49 - Group Anagrams

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-FFA116?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays%20%26%20Hashing-A78BFA?style=for-the-badge)

---

## 📋 Problem

Given an array of strings `strs`, group the anagrams together and return them in any order.

**Example 1:**
```
Input:  strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
```

**Example 2:**
```
Input:  strs = [""]
Output: [[""]]
```

**Constraints:**
- `1 <= strs.length <= 10^4`
- `0 <= strs[i].length <= 100`
- `strs[i]` consists of lowercase English letters

---

> ⏳ C++ and Python solutions coming soon.

---

## 🔵 Solution C

```c
int compare(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    int index = 0;
    int position = 0;
    char **liste = malloc(sizeof(char *) * strsSize);
    char*** resultat = malloc(sizeof(char**) * strsSize);
    int* present = calloc(strsSize, sizeof(int));

    *returnColumnSizes = malloc(sizeof(int) * strsSize);

    for (int i = 0; i < strsSize; i++) {
        liste[i] = strdup(strs[i]);
        qsort(liste[i], strlen(liste[i]), sizeof(char), compare);
    }

    for (int i = 0; i < strsSize; i++) {
        if (present[i] == 1)
            continue;

        resultat[index] = malloc(sizeof(char*) * strsSize);
        position = 0;

        resultat[index][position] = strs[i];
        position++;
        present[i] = 1;

        for (int j = i + 1; j < strsSize; j++) {
            if (present[j] == 0 && strcmp(liste[i], liste[j]) == 0) {
                resultat[index][position] = strs[j];
                position++;
                present[j] = 1;
            }
        }
        (*returnColumnSizes)[index] = position;
        index++;
    }

    *returnSize = index;
    return resultat;
}
```

**Explanation:**
- `compare` — helper function for `qsort` to sort characters alphabetically inside a string.
- `liste` — array of sorted copies of each word. `strdup` duplicates the original string so we don't modify `strs` directly.
- `present` — boolean array (via `calloc`, initialized to 0) to track which words have already been assigned to a group.
- `returnColumnSizes` — out-parameter required by LeetCode to know how many words are in each group.
- First loop — sort a copy of every word and store it in `liste`.
- Second loop (outer) — for each ungrouped word `i`, create a new group in `resultat`.
- Second loop (inner) — compare the sorted version of `i` against every remaining ungrouped word `j`. If they match, add `strs[j]` to the same group and mark it as seen.
- `*returnSize = index` — tell the caller how many groups were created.

---

## 🟣 Solution C++

> Coming soon

---

## 🟡 Solution Python

> Coming soon

---