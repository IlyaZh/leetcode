# 567. Permutation in String

[Leetcode](https://leetcode.com/problems/permutation-in-string/description/)

## Task

> Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
>
> In other words, return true if one of s1's permutations is the substring of s2.

## Complexity

m = len(s1)
n = len(s2)

Time: O(m+n)
Space: O(m+n)

## Solution

```python
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2): return False
            
        m1, m2 = [0] * 26, [0] * 26
        for i in range(len(s1)):
            m1[ord(s1[i]) - ord('a')] += 1
            m2[ord(s2[i]) - ord('a')] += 1

        matches = 0
        for i in range(26):
            matches += (1 if m1[i] == m2[i] else 0)

        l = 0
        for r in range(len(s1), len(s2)):
            if matches == 26: return True

            index = ord(s2[r]) - ord('a')
            m2[index] += 1
            if m1[index] == m2[index]: 
                matches += 1
            elif m1[index] + 1 == m2[index]:
                matches -= 1

            index = ord(s2[l]) - ord('a')
            m2[index] -= 1
            if m1[index] == m2[index]: 
                matches += 1
            elif m1[index] - 1 == m2[index]:
                matches -= 1
            l += 1
        return matches == 26   
          
```
