#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

// Max Heap
void heapifyMax(vector<int> &a, int size, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && a[l] > a[largest])
        largest = l;

    if (r < size && a[r] > a[largest])
        largest = r;

    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapifyMax(a, size, largest);
    }
}

void heapSortMax(vector<int> &a)
{
    int size = a.size();

    for (int i = size / 2 - 1; i >= 0; i--)
        heapifyMax(a, size, i);

    for (int i = size - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapifyMax(a, i, 0);
    }
}

// Min Heap
void heapifyMin(vector<int> &a, int size, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && a[l] < a[smallest])
        smallest = l;

    if (r < size && a[r] < a[smallest])
        smallest = r;

    if (smallest != i)
    {
        swap(a[i], a[smallest]);
        heapifyMin(a, size, smallest);
    }
}

void heapSortMin(vector<int> &a)
{
    int size = a.size();

    for (int i = size / 2 - 1; i >= 0; i--)
        heapifyMin(a, size, i);

    for (int i = size - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapifyMin(a, i, 0);
    }

    reverse(a.begin(), a.end());
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> data(n);

    srand(time(0));
    for (int i = 0; i < n; i++)
        data[i] = rand() % 1000;

    vector<int> maxData = data;
    vector<int> minData = data;

    auto start = high_resolution_clock::now();
    heapSortMax(maxData);
    auto stop = high_resolution_clock::now();

    cout << "Max Heap Sort Time: "
         << duration_cast<microseconds>(stop - start).count()
         << " us\n";

    start = high_resolution_clock::now();
    heapSortMin(minData);
    stop = high_resolution_clock::now();

    cout << "Min Heap Sort Time: "
         << duration_cast<microseconds>(stop - start).count()
         << " us\n";

    return 0;
}
