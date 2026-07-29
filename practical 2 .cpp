#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Linear Search
int linearSearch(vector<int> arr, int key)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Binary Search
int binarySearch(vector<int> arr, int key)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main()
{
    int n = 10000;
    vector<int> arr(n);

    // Fill array with 1 to 10000
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;

    int key;
    cout << "Enter number to search: ";
    cin >> key;

    // Linear Search
    auto start = high_resolution_clock::now();
    int result = linearSearch(arr, key);
    auto stop = high_resolution_clock::now();

    cout << "\nLinear Search" << endl;
    cout << "Index: " << result << endl;
    cout << "Time: "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds" << endl;

    // Binary Search
    start = high_resolution_clock::now();
    result = binarySearch(arr, key);
    stop = high_resolution_clock::now();

    cout << "\nBinary Search" << endl;
    cout << "Index: " << result << endl;
    cout << "Time: "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds" << endl;

    return 0;
}
