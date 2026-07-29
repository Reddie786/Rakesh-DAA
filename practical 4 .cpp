#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Iterative Factorial
long long iterativeFactorial(int n)
{
    long long fact = 1;

    for (int i = 1; i <= n; i++)
        fact = fact * i;

    return fact;
}

// Recursive Factorial
long long recursiveFactorial(int n)
{
    if (n <= 1)
        return 1;

    return n * recursiveFactorial(n - 1);
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Iterative Method
    auto start = high_resolution_clock::now();
    long long iterative = iterativeFactorial(n);
    auto end = high_resolution_clock::now();

    cout << "\nIterative Factorial = " << iterative << endl;
    cout << "Time = "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;

    // Recursive Method
    start = high_resolution_clock::now();
    long long recursive = recursiveFactorial(n);
    end = high_resolution_clock::now();

    cout << "\nRecursive Factorial = " << recursive << endl;
    cout << "Time = "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;

    return 0;
}
