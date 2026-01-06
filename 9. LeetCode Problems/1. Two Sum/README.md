# Two Sum
https://leetcode.com/problems/two-sum/

Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.  \
You may assume that each input would have **exactly one solution**, and you may not use the same element twice.  \
You can return the answer in any order.

### Example 1
> **Input:** nums = [2,7,11,15], target = 9  \
> **Output:** [0,1]  \
> **Explanation:** Because nums[0] + nums[1] == 9, we return [0, 1].

### Example 2
> **Input:** nums = [3,2,4], target = 6  \
> **Output:** [1,2]

### Example 3
> **Input:** nums = [3,3], target = 6  \
> **Output:** [0,1]

### Constraints
> 2 <= nums.length <= 10^4  \
> -10^9 <= nums[i] <= 10^9  \
> -10^9 <= target <= 10^9  \
> Only one valid answer exists.

### Ideas
- For each number in the array, check every other number to see if they add up to the total.
- Could also use a Hash Map to check every input num vs. every other as they are input.

## Usage
```bash
g++ main.cpp
./a.out

Target: # Input your target number.
Input any number of ints, stop input by inputting any non-int.
# Input ints.
```