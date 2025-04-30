Pascal Triangle

class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        const int MOD = 1e9 + 7;
        vector<int> row(n);
        row[0] = 1;  // First element is always 1
        for (int i = 1; i < n; ++i) {
            row[i] = (1LL * row[i - 1] * (n - i)) % MOD;
            row[i] = (1LL * row[i] * pow(i, MOD - 2, MOD)) % MOD;
        }
        return row;
    }

    // Fast modular exponentiation for inverse
    long long pow(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
};
