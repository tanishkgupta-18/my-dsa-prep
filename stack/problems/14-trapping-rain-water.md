```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int water = 0;

        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && height[st.top()] < height[i]) {
                int bottom = st.top();
                st.pop();

                if (st.empty()) break;

                int left = st.top();
                int width = i - left - 1;

                int h = min(height[left], height[i]) - height[bottom];
                water += width * h;
            }
            st.push(i);
        }

        return water;
    }
};
```

```cpp
class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        int left = 0;
        int right = n - 1;

        int leftMax = 0;
        int rightMax = 0;

        int water = 0;

        while (left <= right) {

            if (height[left] <= height[right]) {

                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } 
                else {
                    water += leftMax - height[left];
                }

                left++;
            }

            else {

                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } 
                else {
                    water += rightMax - height[right];
                }

                right--;
            }
        }

        return water;
    }
};
```

> [!note] NOTE
> Why it's correct (the part people usually get stuck on)
> Suppose height[left] < height[right]. You might worry: "what if there's a huge wall just to the right of right, wouldn't that change things?" It doesn't matter, because:
>
>Water level at left is bounded by min(leftMax, max of everything to the right of left).
>You know max of everything to the right of left is at least height[right], which is already > height[left] (and by extension ≥ leftMax if leftMax ≤ height[left], or just generally greater than what's limiting on the left).
>So the left side's water level is never limited by the right side in this case it's fully determined by leftMax. Whatever taller wall exists further right is irrelevant; it can only help, never hurt, the left side's bound.
>This is the crux: you never need the actual max on the far side, just whether it's guaranteed to be at least as large as your current max — and comparing height[left] vs height[right] gives you exactly that guarantee.

