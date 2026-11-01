
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    int weight[100], profit[100];

    for (int i = 0; i < n; i++) {
        cout << "Enter weight and profit of item "
             << i + 1 << ": ";
        cin >> weight[i] >> profit[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    int dp[101][1001] = {0};

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {

            if (weight[i - 1] <= w) {
                dp[i][w] = max(
                    profit[i - 1] +
                    dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum profit = "
         << dp[n][capacity] << endl;

    return 0;
}

