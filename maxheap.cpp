#include <iostream>
using namespace std;

struct Heap {
    int arr[20];
    int size;
};

void heapify(struct Heap *h, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < h->size && h->arr[left] > h->arr[largest])
        largest = left;

    if (right < h->size && h->arr[right] > h->arr[largest])
        largest = right;

    if (largest != i) {
        swap(h->arr[i], h->arr[largest]);
        heapify(h, largest);
    }
}

void buildMaxHeap(struct Heap *h) {
    for (int i = h->size/2 - 1; i >= 0; i--)
        heapify(h, i);
}

int main() {
    struct Heap h;

    h.arr[0] = 10;
    h.arr[1] = 20;
    h.arr[2] = 15;
    h.arr[3] = 30;
    h.arr[4] = 40;
    h.size = 5;

    buildMaxHeap(&h);

    cout << "Max Heap: ";
    for (int i = 0; i < h.size; i++)
        cout << h.arr[i] << " ";

    return 0;
} 