This trick feels confusing at first because it **changes how we think about the graph**. Let’s derive the logic step-by-step so you see **how someone arrives at it**, not just memorize it.

We are solving **Most Stones Removed with Same Row or Column**.

---

# 1️⃣ First Understand the Core Observation

Rule:

You can remove a stone if **another stone exists in the same row or column**.

Important realization:

> Stones that share rows/columns form a **connected component**.

Inside one connected component:

```
we can remove all stones except 1
```

So:

```
answer = total stones − number of connected components
```

This is the **key insight**.

---

# 2️⃣ How Your First Approach Works

Your original approach:

```
compare every pair of stones
```

If:

```
same row OR same column
```

you connect them using DSU.

Graph example:

```
stones:
(0,0)
(0,2)
(1,2)
```

Connections:

```
(0,0) -- (0,2)   same row
(0,2) -- (1,2)   same column
```

Graph:

```
(0,0) ---- (0,2)
              |
            (1,2)
```

This gives **1 component**.

Removable:

```
3 - 1 = 2
```

Correct.

But the problem:

```
we compare all pairs
```

Time:

```
O(n²)
```

---

# 3️⃣ Key Insight to Remove O(n²)

Look carefully at the condition:

```
same row OR same column
```

Instead of connecting **stone ↔ stone**, we can connect:

```
row ↔ column
```

Think of each stone as an **edge** between its row and column.

---

# 4️⃣ Transform the Graph

Stone:

```
(0,2)
```

becomes:

```
Row0 ---- Col2
```

So stones are **edges in a bipartite graph**.

Example:

```
(0,0)
(0,2)
(1,2)
```

Graph becomes:

```
Row0 ---- Col0
  |
  ---- Col2
          |
        Row1
```

Now notice something powerful:

All stones belong to **one connected component**.

So:

```
removable = stones − components
```

---

# 5️⃣ Why DSU Works Here

DSU tracks **connected components**.

When we do:

```
union(row, column)
```

we are building this graph automatically.

Example:

```
union(0 , 0+offset)
union(0 , 2+offset)
union(1 , 2+offset)
```

The DSU structure now represents the **entire connectivity**.

---

# 6️⃣ Why We Add OFFSET

Rows and columns share the same numbers.

Example:

```
row = 2
col = 2
```

If we don't shift:

```
they collide
```

So we map:

```
column -> column + maxRow + 1
```

Example:

```
Row nodes: 0..10000
Column nodes: 10001..20000
```

---

# 7️⃣ Final Formula

Let:

```
C = number of connected components
```

Then:

```
maximum removable stones = total stones − C
```

Because every component must leave **one stone behind**.

---

# 8️⃣ Visual Example

Stones:

```
(0,1)
(1,0)
(1,1)
```

Graph:

```
Row0 -- Col1
          |
Row1 -- Col0
```

Single component.

```
stones = 3
components = 1
answer = 3 - 1 = 2
```

---

# 9️⃣ The Thinking Pattern (Very Important)

When you see problems like this:

```
objects connected by attributes
```

Convert to:

```
attribute nodes
```

Examples:

| Problem                 | Trick               |
| ----------------------- | ------------------- |
| Stones                  | row ↔ column        |
| Accounts Merge          | email ↔ account     |
| Equation Satisfiability | variable ↔ variable |

---

# 🔟 How Experts Recognize This Instantly

They see this structure:

```
A connects to B through a shared attribute
```

So they model:

```
attribute as node
```

This avoids **pairwise comparisons**.

---

✅ **One sentence summary**

Instead of connecting **stones that share row/column**, we connect **rows and columns themselves**, because every stone is simply a link between them.

---

```cpp
class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }

    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) return;

        if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else if (rank[pv] < rank[pu])
            parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {

        int maxRow = 0, maxCol = 0;

        for (auto &s : stones) {
            maxRow = max(maxRow, s[0]);
            maxCol = max(maxCol, s[1]);
        }

        DisjointSet ds(maxRow + maxCol + 2);

        unordered_set<int> nodes;

        for (auto &s : stones) {
            int row = s[0];
            int col = s[1] + maxRow + 1;

            ds.unite(row, col);

            nodes.insert(row);
            nodes.insert(col);
        }

        int components = 0;

        for (auto node : nodes) {
            if (ds.find(node) == node)
                components++;
        }

        return stones.size() - components;
    }
};
```