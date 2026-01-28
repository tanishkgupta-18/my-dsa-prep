```cpp
/*
==================== NOTES: CONTRIBUTION TECHNIQUE ====================

PROBLEM:
Sum of all odd-length subarrays.

KEY IDEA:
Instead of enumerating all subarrays,
count how many times each element arr[i] contributes.

Total Answer = Σ (arr[i] × contribution of arr[i])

-----------------------------------------------------------------------

HOW TO COUNT CONTRIBUTION OF arr[i]:

Fix index i.

Any subarray containing arr[i] can be described by:
left  = number of elements taken on the left of i
right = number of elements taken on the right of i

Subarray length:
len = left + right + 1
(+1 because arr[i] itself is included)

-----------------------------------------------------------------------

ODD LENGTH CONDITION:
len is odd
=> left + right is even

This happens in two cases:
1) left EVEN  and right EVEN
2) left ODD   and right ODD

-----------------------------------------------------------------------

RANGES:
left  ∈ [0 .. i]
right ∈ [0 .. n-1-i]

If a variable ranges from 0 to X:
even count = X/2 + 1
odd  count = (X + 1)/2

-----------------------------------------------------------------------

COUNT ODD-LENGTH SUBARRAYS CONTAINING i:

leftEven  = i/2 + 1
leftOdd   = (i + 1)/2

rightEven = (n - 1 - i)/2 + 1
rightOdd  = (n - i)/2

oddCount = leftEven * rightEven
         + leftOdd  * rightOdd

Contribution of arr[i] = arr[i] * oddCount

-----------------------------------------------------------------------

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

MENTAL MODEL:
Fix an element → choose left & right extensions →
odd length means same parity on both sides.

=======================================================================
*/

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            int leftEven  = i / 2 + 1;
            int leftOdd   = (i + 1) / 2;

            int rightEven = (n - 1 - i) / 2 + 1;
            int rightOdd  = (n - i) / 2;

            int count = leftEven * rightEven
                      + leftOdd  * rightOdd;

            sum += count * arr[i];
        }

        return sum;
    }
};
```