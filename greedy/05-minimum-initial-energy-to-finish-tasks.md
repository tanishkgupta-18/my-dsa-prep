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