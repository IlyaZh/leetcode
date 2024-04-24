# 155. Min Stack [Medium]

[Leetcode](https://leetcode.com/problems/min-stack/description/)

## Task

> Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
> 
> Implement the MinStack class:
>     MinStack() initializes the stack object.
>     void push(int val) pushes the element val onto the stack.
>     void pop() removes the element on the top of the stack.
>     int top() gets the top element of the stack.
>     int getMin() retrieves the minimum element in the stack.
> 
> You must implement a solution with O(1) time complexity for each function.
> 
> Example 1:
> Input
> ["MinStack","push","push","push","getMin","pop","top","getMin"]
> [[],[-2],[0],[-3],[],[],[],[]]
> Output
> [null,null,null,null,-3,null,0,-2]
>  Explanation
> MinStack minStack = new MinStack();
> minStack.push(-2);
> minStack.push(0);
> minStack.push(-3);
> minStack.getMin(); // return -3
> minStack.pop();
> minStack.top();    // return 0
> minStack.getMin(); // return -2
> 
> Constraints:
>     -2^31 <= val <= 2^31 - 1
>     Methods pop, top and getMin operations will always be called on non-empty stacks.
>     At most 3 * 10^4 calls will be made to push, pop, top, and getMin.



## Complexity

Time: O(1) amortized
Space: O(n)

## Solution

Make and array and use it like stack, but for every element store an object with `value` and current minimum.

```python
class MinStack:

    def __init__(self):
        self.data = []

    def push(self, val: int) -> None:
        if self.data:
            self.data.append({'val': val, 'min': min(val, self.data[-1]['min'])})
        else:
            self.data.append({'val': val, 'min': val})

    def pop(self) -> None:
        self.data.pop()

    def top(self) -> int:
        return self.data[-1]['val']

    def getMin(self) -> int:
        return self.data[-1]['min']


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
```