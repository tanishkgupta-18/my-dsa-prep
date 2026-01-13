#include <iostream>
#include <vector>
using namespace std;

int build(int ss, int se, int si, vector<int>& arr, vector<int>& tree)
{
    if (ss == se)
        return tree[si] = arr[ss];

    int mid = (ss + se) / 2;
    return tree[si] =
        build(ss, mid, 2 * si + 1, arr, tree) +
        build(mid + 1, se, 2 * si + 2, arr, tree);
}

int getSum(int qs, int qe, int ss, int se, int si, vector<int>& tree)
{
    if (se < qs || ss > qe)
        return 0;

    if (qs <= ss && qe >= se)
        return tree[si];

    int mid = (ss + se) / 2;
    return getSum(qs, qe, ss, mid, 2 * si + 1, tree) +
           getSum(qs, qe, mid + 1, se, 2 * si + 2, tree);
}

void update(int ss, int se, int si, int idx, int diff, vector<int>& tree)
{
    if (idx < ss || idx > se)
        return;

    tree[si] += diff;

    if (ss != se)
    {
        int mid = (ss + se) / 2;
        update(ss, mid, 2 * si + 1, idx, diff, tree);
        update(mid + 1, se, 2 * si + 2, idx, diff, tree);
    }
}

int main()
{
    vector<int> arr = {10, 20, 30, 40};
    int n = arr.size();

    vector<int> tree(4 * n);
    build(0, n - 1, 0, arr, tree);

    cout << getSum(1, 3, 0, n - 1, 0, tree) << endl;

    int idx = 1;
    int newVal = 25;
    int diff = newVal - arr[idx];
    arr[idx] = newVal;

    update(0, n - 1, 0, idx, diff, tree);

    cout << getSum(1, 3, 0, n - 1, 0, tree) << endl;

    return 0;
}
