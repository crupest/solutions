class Solution {
public:
    // catalan number:
    // f(n) = f(0) * f(n-1) + f(1) * f(n-2) + ... + f(n-1)*f(0)
    // f(n) = 2(2n-1) * f(n-1) / (n+1)
    // f(n) = C(2n, n) / (n+1)
    int numTrees(int n) {
        long long result = 1;
        for (int i = 2; i <= n; i++) {
            result = 2 * (2 * i - 1) * result / (i + 1);
        }
        return result;
    }
};
