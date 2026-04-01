#include <iostream>
using namespace std;

// Swap function
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Min heapify function
void heapify(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

// Min Heap Sort
void heapSort(int arr[], int n)
{
    // Build min heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements
    for (int i = n-1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Print array
void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {40, 10, 30, 20, 15};
    int n = 5;

    heapSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}