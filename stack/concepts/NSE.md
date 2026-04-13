## NEXT SMALLER ELEMENT
```cpp
vector<int> nextSmallerElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> stk;

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {

        // Pop elements from the stack that are greater
        // than or equal to the current element
        while (!stk.empty() && stk.top() >= arr[i]) {
            stk.pop();
        }

        // If the stack is not empty, the top element
        // is the next smaller element
        if (!stk.empty()) {
            res[i] = stk.top();
        }

        // Push the current element onto the stack
        stk.push(arr[i]);
    }

    return res;
}
```