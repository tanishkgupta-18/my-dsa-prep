```cpp
class Solution {
public:
    static const int MOD = 1e9 + 7;
    static const int MAXN = 200005;

    long long fact[MAXN], invFact[MAXN];

    // Fast exponentiation
    long long power(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }

    // Precompute factorials and inverse factorials
    void precompute() {
        fact[0] = 1;
        for (int i = 1; i < MAXN; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        invFact[MAXN - 1] = power(fact[MAXN - 1], MOD - 2);

        for (int i = MAXN - 2; i >= 0; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
    }

    // nCr function
    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return (fact[n] * invFact[r] % MOD * invFact[n - r] % MOD) % MOD;
    }

    int countVisiblePeople(int n, int pos, int k) {
        precompute();

        if (k > n - 1) return 0;

        long long comb = nCr(n - 1, k);

        return (2 * comb) % MOD;
    }
};
```