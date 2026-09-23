#include <iostream>
#include <algorithm>
#include <chrono>
#include <cstring>
using namespace std;
using namespace chrono;

int n, capacity;
int weight[100], value[100];
int memo[100][100];   // memo[i][w] = -1 means "not solved yet"

// Recursive function with memoization
int solve(int i, int w)
{
    // Base case: no items left OR no capacity left
    if (i == 0 || w == 0)
        return 0;

    // If this subproblem is already solved, return stored answer
    if (memo[i][w] != -1)
        return memo[i][w];

    int result;

    if (weight[i - 1] > w)
    {
        // Item doesn't fit, skip it
        result = solve(i - 1, w);
    }
    else
    {
        // Choice: EXCLUDE item i-1  vs  INCLUDE item i-1
        int exclude = solve(i - 1, w);
        int include = value[i - 1] + solve(i - 1, w - weight[i - 1]);
        result = max(include, exclude);
    }

    // Store before returning (this is the "memoization" step)
    memo[i][w] = result;
    return result;
}

int main()
{
    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
        cin >> value[i];

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    memset(memo, -1, sizeof(memo));   // mark all subproblems as "unsolved"

    auto start = high_resolution_clock::now();
    int maxValue = solve(n, capacity);
    auto end = high_resolution_clock::now();

    auto nano  = duration_cast<nanoseconds>(end - start);
    auto micro = duration_cast<microseconds>(end - start);
    auto milli = duration_cast<milliseconds>(end - start);

    cout << "\n========== 0/1 KNAPSACK (Recursive + Memoization) ==========\n";
    cout << "Maximum value : " << maxValue << endl;

    cout << "\n========== EXECUTION TIME ==========\n";
    cout << "Nanoseconds  : " << nano.count() << " ns\n";
    cout << "Microseconds : " << micro.count() << " us\n";
    cout << "Milliseconds : " << milli.count() << " ms\n";

    return 0;
}

 
