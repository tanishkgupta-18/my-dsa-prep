```cpp
/*
Statement:
    tasks[i] = [actual, minimum]
    actual to finish a task
    minimum to start the task

    find min initial energy to finish all tasks

Observation:
    Energyi + sum of actual uptil i >= minimumi
    Energy_min = max(sum of prev actual + minimum)
     
    to find minimum energy we need an order that minimize sum of prev actual + minimum
    then sort the array on the basis of minimum - actual in descending order



*/


class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const auto& a, const auto& b) {
            return a[1] - a[0] > b[1] - b[0];
        });

        int energy = 0;
        int spent = 0;

        for (auto& task : tasks) {
            int actual = task[0];
            int minimum = task[1];

            energy = max(energy, spent + minimum);
            spent += actual;
        }

        return energy;
    }
};
```

Yes. Let's derive the **current problem from scratch using exactly that contest method**, without starting with `minimum - actual`.

---

# 1. What are we minimizing?

For a fixed order of tasks:

```text
task = [actual, minimum]
```

Suppose we've already spent `spent` energy.

To start the current task, we need:

$$
initialEnergy - spent \ge minimum
$$

Therefore:

$$
initialEnergy \ge spent + minimum
$$

So for a particular ordering:

$$
\boxed{answer = \max(spent + minimum)}
$$

Now the question becomes:

> **What ordering minimizes this maximum?**

This tells us that **order matters**, so let's use the two-element method.

---

# 2. Take two tasks

Let:

```text
A = [a, mA]
B = [b, mB]
```

where:

* `a` = actual energy consumed by A
* `mA` = minimum energy required by A
* `b` = actual energy consumed by B
* `mB` = minimum energy required by B

Ignore everything before these two tasks. Suppose we've already spent `S` energy.

We'll compare:

```text
A → B
```

against:

```text
B → A
```

---

# 3. Try A → B

Before `A`:

$$
E \ge S + m_A
$$

After doing `A`, we've spent `a` more energy.

Before `B`:

$$
E \ge S + a + m_B
$$

Therefore:

$$
E_{AB} = S + \max(m_A,\ a+m_B)
$$

Since `S` is common to both orders, we can ignore it while comparing.

So:

$$
AB = \max(m_A,\ a+m_B)
$$

---

# 4. Try B → A

Similarly:

$$
BA = \max(m_B,\ b+m_A)
$$

Now we have exactly what we wanted:

$$
\boxed{
\max(m_A,\ a+m_B)
\quad\text{vs}\quad
\max(m_B,\ b+m_A)
}
$$

We need to determine which ordering is better.

---

# 5. Find when A should come first

We want:

$$
\max(m_A,\ a+m_B)
\le
\max(m_B,\ b+m_A)
$$

Instead of trying to memorize this expression, consider what happens depending on which minimum requirement is larger.

### Suppose `mA >= mB`

The right side is:

$$
\max(m_B,\ b+m_A)
$$

Since `b > 0`:

$$
b+m_A > m_A \ge m_B
$$

Therefore:

$$
BA = b+m_A
$$

For `A → B`:

$$
AB = \max(m_A,\ a+m_B)
$$

So `A → B` is better when:

$$
\max(m_A,\ a+m_B) \le b+m_A
$$

The first part is automatically satisfied:

$$
m_A \le b+m_A
$$

So we only need:

$$
a+m_B \le b+m_A
$$

Rearrange:

$$
m_A-a \ge m_B-b
$$

And there it is:

$$
\boxed{m_A-a \ge m_B-b}
$$

---

# 6. What did we discover?

For `A` to come before `B`:

$$
minimum_A - actual_A
\ge
minimum_B - actual_B
$$

Therefore the optimal ordering is:

```text
sort by (minimum - actual) descending
```

We didn't guess it.

We started with:

```text
What am I minimizing?
        ↓
answer = max(spent + minimum)
        ↓
Order matters
        ↓
Take two tasks
        ↓
Compare A → B vs B → A
        ↓
Derive condition
        ↓
minimum - actual
```

---

# 7. Now the code becomes obvious

Once we have the comparator:

```cpp
sort(tasks.begin(), tasks.end(), [](const auto& a, const auto& b) {
    return a[1] - a[0] > b[1] - b[0];
});
```

we just calculate the maximum requirement:

```cpp
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const auto& a, const auto& b) {
            return a[1] - a[0] > b[1] - b[0];
        });

        int spent = 0;
        int answer = 0;

        for (auto& task : tasks) {
            answer = max(answer, spent + task[1]);
            spent += task[0];
        }

        return answer;
    }
};
```

### The contest takeaway

The important thing isn't remembering:

> "`minimum - actual` → descending."

Remember this instead:

> **If a problem asks me to arrange things optimally, compare two neighboring elements in both possible orders. The condition under which `A → B` is better becomes my sorting comparator.**

That method is what lets you derive this solution even when the sorting rule isn't intuitive.
