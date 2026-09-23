#include <iostream>
#include <climits>
using namespace std;

int matrixChainMultiplication(int p[], int n) {
    // dp[i][j] = minimum number of multiplications
    // needed to multiply matrices i through j
    int dp[n][n];

    // Cost is 0 when multiplying one matrix
    for (int i = 1; i < n; i++)
        dp[i][i] = 0;

    // chain length
    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    return dp[1][n - 1];
}

int main() {
    // Matrices:
    // A1 = 10 x 20
    // A2 = 20 x 30
    // A3 = 30 x 40
    // A4 = 40 x 30

    int p[] = {10, 20, 30, 40, 30};
    int n = sizeof(p) / sizeof(p[0]);

    cout << "Minimum number of scalar multiplications = "
         << matrixChainMultiplication(p, n);

    return 0;
}
