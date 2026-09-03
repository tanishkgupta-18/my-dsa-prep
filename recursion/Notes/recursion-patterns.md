Nearly every recursive problem on LeetCode falls into one of **7 core archetypes**. Once you recognize which pattern a problem maps to, the recursive structure, base cases, and state transitions follow mechanical rules.

---

### Pattern 1: Pick / Not Pick (0/1 Subsequences & Knapsack)

Use this when each element can be chosen at most once and order in the input matters (subsets, subsequences).

* **Decision per level:** 2 branches—include `nums[idx]` or exclude it.
* **Key LeetCode Problems:** LC 78 (Subsets), LC 416 (Partition Equal Subset Sum), LC 494 (Target Sum).

```cpp
void backtrack(int idx, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {
    if (idx == nums.size()) {
        ans.push_back(curr);
        return;
    }

    // Choice 1: Pick
    curr.push_back(nums[idx]);
    backtrack(idx + 1, nums, curr, ans);

    // Choice 2: Not Pick (Backtrack)
    curr.pop_back();
    backtrack(idx + 1, nums, curr, ans);
}

```

---

### Pattern 2: Multi-Branch Loop with Backtracking (Combinations & Deduplication)

Use this when you need combinations of arbitrary length, or when handling **duplicates**. Sorting the input array first is mandatory for duplicate elimination.

* **Decision per level:** A `for` loop over candidates starting from `start_idx`.
* **Deduplication Trick:** `if (i > start_idx && nums[i] == nums[i - 1]) continue;`
* **Key LeetCode Problems:** LC 90 (Subsets II), LC 77 (Combinations), LC 40 (Combination Sum II).

```cpp
void findCombinations(int start, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {
    ans.push_back(curr); // or check a target sum base condition

    for (int i = start; i < nums.size(); ++i) {
        // Skip duplicates at the same tree depth
        if (i > start && nums[i] == nums[i - 1]) continue;

        curr.push_back(nums[i]);
        findCombinations(i + 1, nums, curr, ans); // use i instead of i + 1 if elements can be reused
        curr.pop_back();                          // backtrack
    }
}

```

---

### Pattern 3: Permutations (Element Ordering / Visited Array)

Use this when every element must appear, but the order changes.

* **Decision per level:** Any unvisited element can be placed next.
* **Variant A:** Extra space via a boolean `visited` array.
* **Variant B (In-Place):** Swap elements directly in the array.
* **Key LeetCode Problems:** LC 46 (Permutations), LC 47 (Permutations II).

```cpp
// In-place swap pattern: O(1) auxiliary space beyond recursion stack
void permute(int idx, vector<int>& nums, vector<vector<int>>& ans) {
    if (idx == nums.size()) {
        ans.push_back(nums);
        return;
    }

    unordered_set<int> seen; // handles duplicates if nums has duplicates (LC 47)
    for (int i = idx; i < nums.size(); ++i) {
        if (seen.count(nums[i])) continue;
        seen.insert(nums[i]);

        swap(nums[idx], nums[i]);
        permute(idx + 1, nums, ans);
        swap(nums[idx], nums[i]); // backtrack
    }
}

```

---

### Pattern 4: Partitioning & String Exploration

Use this when you must cut a string or array into valid sub-segments (e.g., words, palindromes, valid IPs).

* **Decision per level:** Where to place the *next cut* `i` from `start` to `end`.
* **Key LeetCode Problems:** LC 131 (Palindrome Partitioning), LC 139 (Word Break), LC 93 (Restore IP Addresses).

```cpp
bool isValid(const string& s, int start, int end); // helper

void partition(int start, const string& s, vector<string>& curr, vector<vector<string>>& ans) {
    if (start == s.size()) {
        ans.push_back(curr);
        return;
    }

    for (int end = start; end < s.size(); ++end) {
        if (isValid(s, start, end)) {
            curr.push_back(s.substr(start, end - start + 1));
            partition(end + 1, s, curr, ans);
            curr.pop_back(); // backtrack
        }
    }
}

```

---

### Pattern 5: 2D Grid Traversal / Flood Fill

Use this for exploring connected components, mazes, and boards.

* **Decision per level:** Move in 4 or 8 directions (`dr = {-1, 1, 0, 0}`, `dc = {0, 0, -1, 1}`).
* **State alteration:** Mark the cell visited (often by modifying the grid in-place, e.g., `'1'` $\to$ `'0'`), recurse, then unmark if multiple paths can traverse the cell.
* **Key LeetCode Problems:** LC 200 (Number of Islands), LC 79 (Word Search), LC 51 (N-Queens).

```cpp
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool searchWord(int r, int c, int idx, vector<vector<char>>& board, const string& word) {
    if (idx == word.size()) return true;
    if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != word[idx]) {
        return false;
    }

    char original = board[r][c];
    board[r][c] = '#'; // mark visited

    for (int i = 0; i < 4; ++i) {
        if (searchWord(r + dr[i], c + dc[i], idx + 1, board, word)) return true;
    }

    board[r][c] = original; // backtrack
    return false;
}

```

---

### Pattern 6: Tree / DAG Recursion (Divide & Conquer)

Use this when subproblems are naturally hierarchical and disjoint (trees, expressions, merge sort).

* **Decision per level:** Solve left and right child subproblems, then merge results at the current node.
* **Key LeetCode Problems:** LC 104 (Max Depth of Binary Tree), LC 124 (Binary Tree Maximum Path Sum), LC 241 (Different Ways to Add Parentheses).

```cpp
struct TreeNode {
    int val;
    TreeNode *left, *right;
};

int maxPathDown(TreeNode* root, int& max_sum) {
    if (!root) return 0;

    // Prune negative paths with max(0, ...)
    int left = max(0, maxPathDown(root->left, max_sum));
    int right = max(0, maxPathDown(root->right, max_sum));

    // Update global result using current node as the turn-around point
    max_sum = max(max_sum, left + right + root->val);

    // Return best single branch to caller
    return root->val + max(left, right);
}

```

---

### Pattern 7: Memoized Recursion (Top-Down Dynamic Programming)

Use this when the recursion tree visits the **same states** repeatedly.

* **Conversion rule:** Any recursive function whose answer depends solely on its index and remaining target can be wrapped in a lookup table.
* **State Identification:** Every variable that changes in the recursive call becomes a dimension in your DP array.
* **Key LeetCode Problems:** LC 322 (Coin Change), LC 1143 (Longest Common Subsequence), LC 72 (Edit Distance).

```cpp
int memo[1001][1001]; // Initialize with -1

int solve(int i, int j, const string& s1, const string& s2) {
    // Base cases
    if (i == s1.size() || j == s2.size()) return 0;

    if (memo[i][j] != -1) return memo[i][j];

    if (s1[i] == s2[j]) {
        return memo[i][j] = 1 + solve(i + 1, j + 1, s1, s2);
    }

    return memo[i][j] = max(solve(i + 1, j, s1, s2), solve(i, j + 1, s1, s2));
}

```

---

### Universal Pattern Matcher Table

| Input Characteristic | Goal / Output | Matching Pattern |
| --- | --- | --- |
| Array, subsets, knapsack | Combinations / Subsets | **Pattern 1 (Pick / Not Pick)** |
| Array with duplicates | Unique Subsets / Combinations | **Pattern 2 (Loop + Duplicate Skip)** |
| Array / String | All orderings / permutations | **Pattern 3 (Swap / Visited Array)** |
| String decomposition | Segmenting into valid pieces | **Pattern 4 (Partitioning)** |
| Matrix / Board | Pathfinding, Word Search | **Pattern 5 (Grid Backtracking)** |
| Binary Tree / Disjoint structures | Tree Properties / Aggregation | **Pattern 6 (Divide & Conquer)** |
| Overlapping subproblems | Min/Max/Count optimizations | **Pattern 7 (Top-Down Memoization)** |