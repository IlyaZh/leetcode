# 17. Letter Combinations of a Phone Number [Medium]

[Leetcode](https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/)

## Task

> Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
> 
> A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
> 
> Example 1:
> Input: digits = "23"
> Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
> 
> Example 2:
> Input: digits = ""
> Output: []
> 
> Example 3:
> Input: digits = "2"
> Output: ["a","b","c"]
> 
> Constraints:
>     0 <= digits.length <= 4
>     digits[i] is a digit in the range ['2', '9'].


## Complexity

Time: O(n)
Space: O(n^2)

## Solution


```python
class Solution:      
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits: return []
        m = {
             '2': ['a', 'b', 'c'],
             '3': ['d','e','f'],
             '4': ['g','h','i'],
             '5': ['j', 'k', 'l'],
             '6': ['m', 'n', 'o'],
             '7': ['p', 'q', 'r', 's'],
             '8': ['t','u','v'],
             '9': ['w','x','y','z']}
        result = []

        for digit in digits:
            letters = m[digit]
            temp = []
            if not result:
                result = letters
                continue

            for r in result:
                for letter in letters:
                    temp.append(r+letter)
            result = temp
                
        return result
```