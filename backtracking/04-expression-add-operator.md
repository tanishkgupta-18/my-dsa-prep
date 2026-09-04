```cpp
class Solution {
public:
    vector<string> ans;

    void solve(int pos, string& num, long long target,
               string& expr, long long value, long long last) {

        if (pos == num.size()) {
            if (value == target)
                ans.push_back(expr);

            return;
        }

        for (int i = pos; i < num.size(); i++) {

            // Leading zero is not allowed
            if (i > pos && num[pos] == '0')
                break;

            string curr = num.substr(pos, i - pos + 1);
            long long x = stoll(curr);

            // First number: no operator before it
            if (pos == 0) {

                expr += curr;

                solve(i + 1, num, target,
                      expr, x, x);

                expr.resize(expr.size() - curr.size());
            }
            else {

                // +
                expr += "+" + curr;

                solve(i + 1, num, target,
                      expr, value + x, x);

                expr.resize(expr.size() - curr.size() - 1);

                // -
                expr += "-" + curr;

                solve(i + 1, num, target,
                      expr, value - x, -x);

                expr.resize(expr.size() - curr.size() - 1);

                // *
                expr += "*" + curr;

                solve(i + 1, num, target,
                      expr, value - last + last * x, last * x);

                expr.resize(expr.size() - curr.size() - 1);
            }
        }
    }

    vector<string> addOperators(string num, int target) {

        string expr;

        solve(0, num, target, expr, 0, 0);

        return ans;
    }
};
```