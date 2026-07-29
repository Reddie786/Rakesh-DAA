#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Bubble Sort
void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

// Selection Sort
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        swap(arr[i], arr[minIndex]);
    }
}

// Insertion Sort
void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort
void merge(vector<int> &arr, int l, int m, int r)
{
    vector<int> temp;
    int i = l, j = m + 1;

    while (i <= m && j <= r)
    {
        if (arr[i] < arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= m) temp.push_back(arr[i++]);
    while (j <= r) temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++)
        arr[l + k] = temp[k];
}

void mergeSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Quick Sort
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main()
{
    int n = 5000;
    vector<int> arr(n), temp;

    srand(time(0));

    for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000;

    cout << "Number of Elements: " << n << endl;

    // Bubble Sort
    temp = arr;
    auto start = high_resolution_clock::now();
    bubbleSort(temp);
    auto stop = high_resolution_clock::now();
    cout << "Bubble Sort: "
         << duration_cast<milliseconds>(stop - start).count()
         << " ms" << endl;

    // Selection Sort
    temp = arr;
    start = high_resolution_clock::now();
    selectionSort(temp);
    stop = high_resolution_clock::now();
    cout << "Selection Sort: "
         << duration_cast<milliseconds>(stop - start).count()
         << " ms" << endl;

    // Insertion Sort
    temp = arr;
    start = high_resolution_clock::now();
    insertionSort(temp);
    stop = high_resolution_clock::now();
    cout << "Insertion Sort: "
         << duration_cast<milliseconds>(stop - start).count()
         << " ms" << endl;

    // Merge Sort
    temp = arr;
    start = high_resolution_clock::now();
    mergeSort(temp, 0, n - 1);
    stop = high_resolution_clock::now();
    cout << "Merge Sort: "
         << duration_cast<milliseconds>(stop - start).count()
         << " ms" << endl;

    // Quick Sort
    temp = arr;
    start = high_resolution_clock::now();
    quickSort(temp, 0, n - 1);
    stop = high_resolution_clock::now();
    cout << "Quick Sort: "
         << duration_cast<milliseconds>(stop - start).count()
         << " ms" << endl;

    return 0;
}
