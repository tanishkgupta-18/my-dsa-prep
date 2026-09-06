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