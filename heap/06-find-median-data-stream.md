```cpp
class MedianFinder {
private:
    priority_queue<int> left; // max heap
    priority_queue<int, vector<int>, greater<int>> right; // min heap

public:
    MedianFinder() {
    }

    void addNum(int num) {

        // Step 1: Put num into one of the heaps
        if (left.empty() || num <= left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }

        // Step 2: Balance the heaps

        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }

        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {

        if (left.size() > right.size()) {
            return left.top();
        }

        return (left.top() + right.top()) / 2.0;
    }
};
```