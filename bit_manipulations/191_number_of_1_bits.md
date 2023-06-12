# 191. Number of 1 Bits

[Leetcode](https://leetcode.com/problems/number-of-1-bits/)

## Task

> Write a function that takes the binary representation of an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

## Complexity

Time: O(n) - n count of 1 bits
Space: O(1) - no extra space 

## Solution

```c++
class Solution {
public:
   int hammingWeight(uint32_t n) {
       uint32_t mask = 0x01;
       int count = 0;
       while(n) {
           n &= (n-1);
           ++count;
       }
       return count;
   }
};
```