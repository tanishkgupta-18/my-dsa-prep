# Binary Search — Boundary (Contest) Templates

#### 1. The "Specific Value" Search (while l <= r)
- **Use when:** You need to find a unique target and can stop early.
- **Logic:**
  ```cpp
  while (l <= r) {
      int mid = l + (r - l) / 2;
      if (arr[mid] == target) return mid;
      if (arr[mid] < target) l = mid + 1;
      else r = mid - 1;
  }
---
Binary search is not about finding an element.
It is about finding a **boundary where a condition flips**.

Think in terms of a hidden boolean array:

```
F F F F T T T T
        ^
     boundary
```

You can only check `isTrue(mid)`.

---

## Core Invariant (very important)

> **The answer is always inside `[l, r]`**

We never discard the boundary.

That’s why we use:

```
while (l < r)
```

Not `l <= r`.

---

# Template 1 — Find **First TRUE** (Minimum valid value)

Use when problem asks:

* Minimum value such that condition holds
* lower_bound
* First bad version
* Koko bananas
* Ship packages
* Smallest divisor
* Bouquets
* Split array largest sum

### Pattern

```cpp
int l = MIN_ANSWER;
int r = MAX_ANSWER;
while (l < r) {
    int mid = l + (r - l) / 2;   // round DOWN

    if (isTrue(mid))
        r = mid;        // keep mid
    else
        l = mid + 1;    // discard mid
}

return l;
```

### Why `r = mid`?

Because `mid` might be the first TRUE. We must keep it.

---

# Template 2 — Find **Last TRUE** (Maximum valid value)

Use when problem asks:

* Maximum value such that condition holds
* Upper bound style
* Magnetic force / Aggressive cows
* Maximize minimum distance
* Any "maximize the minimum" problem

### Pattern

```cpp
int l = MIN_ANSWER;
int r = MAX_ANSWER;
while (l < r) {
    int mid = l + (r - l + 1) / 2;   // round UP

    if (isTrue(mid))
        l = mid;        // keep mid
    else
        r = mid - 1;    // discard mid
}

return l;
```

### Why `+1` in mid?

To avoid infinite loop when `l` and `r` are adjacent.

---

# How to Decide Which Template?

Ask:

| Question             | Template   |
| -------------------- | ---------- |
| Minimum valid value? | First TRUE |
| Maximum valid value? | Last TRUE  |

---

# Mapping to Lower / Upper Bound

| Operation              | Template                     |
| ---------------------- | ---------------------------- |
| `lower_bound(x)`       | First TRUE where `a[i] >= x` |
| `upper_bound(x)`       | First TRUE where `a[i] > x`  |
| Last occurrence of `x` | Last TRUE where `a[i] <= x`  |

---

# Mental Model

Do **not** think:

> how to move `l` and `r`

Think:

> what is `isTrue(mid)`?

Everything else follows the template.

---

# Key Differences from Classic `l <= r`

| Classic BS (`l <= r`)       | Boundary BS (`l < r`)    |
| --------------------------- | ------------------------ |
| Search an index             | Search a boundary        |
| Needs `ans` variable        | No `ans` needed          |
| Uses `mid - 1` / `mid + 1`  | Keeps boundary always    |
| Error-prone in BS on answer | Perfect for BS on answer |

---

# One-Line Summary

> Binary search in contests = **Find boundary where condition flips**.
