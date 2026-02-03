# ✅ Template 1 — **First TRUE** (Minimum valid value)

Use when truth pattern is:

```
F F F F T T T
        ^
     answer (minimum)
```

Examples:

* Minimum radius / distance
* Minimize maximum gap (gas station)
* Minimum time / speed problems on doubles

```cpp
double firstTrue(double low, double high) {
    for (int i = 0; i < 100; i++) {
        double mid = low + (high - low) / 2.0;

        if (check(mid))
            high = mid;   // keep mid
        else
            low = mid;    // discard mid
    }
    return high;  // minimum valid
}
```

---

# ✅ Template 2 — **Last TRUE** (Maximum valid value)

Use when truth pattern is:

```
T T T T F F F
      ^
   answer (maximum)
```

Examples:

* Maximum average subarray
* Maximum possible value under constraint

```cpp
double lastTrue(double low, double high) {
    for (int i = 0; i < 100; i++) {
        double mid = low + (high - low) / 2.0;

        if (check(mid))
            low = mid;    // keep mid
        else
            high = mid;   // discard mid
    }
    return low;  // maximum valid
}
```

---

## 🧠 How to choose?

Ask:

| Question                                 | Template   |
| ---------------------------------------- | ---------- |
| Minimum value such that condition holds? | First TRUE |
| Maximum value such that condition holds? | Last TRUE  |

---

## 🧩 Notes

* `check(mid)` must be **monotonic**
* 100 iterations → precision better than `1e-9`
* Use **fixed iterations** (not `while(low < high)`) because doubles never converge cleanly.

