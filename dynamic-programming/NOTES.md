
---

# 🧠 What Dynamic Programming Actually Is

DP is simply:

> **Caching answers of overlapping subproblems in a decision process.**

Mathematically:

```
answer(state) = best over choices (transition)
```

So every DP problem has **3 components**:

1️⃣ **State** → what information defines the subproblem
2️⃣ **Choices** → decisions you can make from that state
3️⃣ **Transition** → how the state changes

```
dp[state] = best(choice1, choice2, choice3...)
```

---

# Step 1 — Identify the STATE

The **state is the minimum information required to continue the problem**.

Ask yourself:

> “What information do I need to know to continue making decisions?”

Examples:

### Example 1 — House Robber

You only need the **current index**.

```
dp[i] = max money starting from house i
```

---

### Example 2 — Longest Increasing Subsequence

You need:

```
current index
previous chosen element
```

State:

```
dp[i][prev]
```

---

### Example 3 — Knapsack

You need:

```
index of item
remaining capacity
```

State:

```
dp[i][w]
```

---

# Step 2 — Identify the CHOICES

Every DP problem is basically **a decision tree**.

Ask:

> “What options do I have at this state?”

Example:

### House Robber

At house `i`:

```
1. rob it
2. skip it
```

---

### Knapsack

At item `i`:

```
1. take item
2. skip item
```

---

### LIS

At index `i`:

```
1. include nums[i]
2. skip nums[i]
```

---

# Step 3 — Build the TRANSITION

Now simply convert the decision into an equation.

### House Robber

If rob:

```
nums[i] + dp[i+2]
```

If skip:

```
dp[i+1]
```

Transition:

```
dp[i] = max(nums[i] + dp[i+2], dp[i+1])
```

---

### Knapsack

If take:

```
value[i] + dp[i+1][w-weight[i]]
```

If skip:

```
dp[i+1][w]
```

Transition:

```
dp[i][w] = max(
    value[i] + dp[i+1][w-weight[i]],
    dp[i+1][w]
)
```

---

# Step 4 — Add Base Cases

Base cases are simply **where the recursion stops**.

House robber:

```
if(i >= n) return 0
```

Knapsack:

```
if(i == n) return 0
```

---

# Step 5 — Memoization

Store answers so we don't recompute.

```
vector<int> memo(n, -1)
```

---

# Example — Full Thought Process

Problem: **House Robber**

Input:

```
[2,7,9,3,1]
```

---

### Step 1: State

```
dp[i] = max money starting from i
```

---

### Step 2: Choices

```
rob
skip
```

---

### Step 3: Transition

```
dp[i] = max(
    nums[i] + dp[i+2],
    dp[i+1]
)
```

---

### Step 4: Base Case

```
i >= n → return 0
```

---

### Final Code

```cpp
class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& memo){
        if(i >= nums.size()) return 0;

        if(memo[i] != -1) return memo[i];

        int take = nums[i] + solve(i+2, nums, memo);
        int skip = solve(i+1, nums, memo);

        return memo[i] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return solve(0, nums, memo);
    }
};
```

---

# ⚡ The 6 Major DP Patterns

Once you recognize these, **most DP problems become easy**.

---

# 1️⃣ Take / Skip Pattern

State:

```
index
```

Transition:

```
dp[i] = max(take, skip)
```

Problems:

* House Robber
* Maximum Non Adjacent Sum
* Delete and Earn

---

# 2️⃣ Linear DP

Each state depends on previous states.

Example:

```
dp[i] = dp[i-1] + dp[i-2]
```

Problems:

* Fibonacci
* Climbing Stairs
* Decode Ways

---

# 3️⃣ Knapsack DP

State:

```
item index + capacity
```

Problems:

* 0/1 Knapsack
* Coin Change
* Target Sum

---

# 4️⃣ Interval DP

State:

```
dp[l][r]
```

Problems:

* Matrix Chain Multiplication
* Burst Balloons
* Palindrome Partitioning

---

# 5️⃣ LIS Type DP

State:

```
index + previous element
```

Problems:

* Longest Increasing Subsequence
* Russian Doll Envelopes

---

# 6️⃣ Grid DP

State:

```
row + column
```

Problems:

* Unique Paths
* Minimum Path Sum

---

# 🔥 The Competitive Programmer Trick

Convert the problem into a **state graph**.

Example House Robber:

```
0 → 1
0 → 2
1 → 2
1 → 3
```

Then compute **maximum path value**.

---

# ⚡ The Fast DP Derivation Method

Whenever you see a problem:

1️⃣ Define state
2️⃣ List choices
3️⃣ Write transition
4️⃣ Add base case

```
state → choices → transition
```

---


