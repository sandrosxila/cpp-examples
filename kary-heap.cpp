#include <bits/stdc++.h>
using namespace std;

template <typename T> class KaryHeap {
  private:
  int capacity;
  int k;
  int size;
  T *arr;


  // Get the parent index
  int parent(int i, int k) {
      return (i - 1) / k;
  }

  // Get the child index
  int child(int i, int j, int k) {
      return k * i + j + 1;
  }

  // Sift-up operation (used in insert)
  void siftUp(int i) {
      while (i > 0 && arr[parent(i, k)] > arr[i]) {
          swap(arr[parent(i, k)], arr[i]);
          i = parent(i, k);
      }
  }
  
  // Sift-down operation (used in extractMin)
  void siftDown(int i) {
      while (true) {
          int smallest = i;
          for (int j = 0; j < k; j++) {
              int c = child(i, j, k);
              if (c < size && arr[c] < arr[smallest]) {
                  smallest = c;
              }
          }
          if (smallest == i) break;
          swap(arr[i], arr[smallest]);
          i = smallest;
      }
  }

  public:
  KaryHeap(int capacity, int k) : capacity(capacity), k(k), size(0) {
    arr = new T[capacity];
  }

  // Insert a new element into the heap
  void insert(int value) {
      if (size == capacity) {
          cerr << "Heap is full!" << endl;
          return;
      }

      arr[size] = value; // Insert at the end
      siftUp(size); // Restore heap property
      size++;
  }

  // Extract the minimum element
  int extractMin() {
      if (size == 0) {
          cerr << "Heap is empty!" << endl;
          return -1;
      }
      int min = arr[0];
      arr[0] = arr[--size]; // Replace root with last element
      siftDown(0); // Restore heap property
      return min;
  }

  // Print the heap
  void printHeap(KaryHeap *heap) {
      
  }

  void print() {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
  }

  ~KaryHeap() {
    delete arr;
  }
};

// Main function for testing
int main() {
    int k = 3;  // Ternary heap
    KaryHeap<int> heap(20, k);

    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(30);
    heap.insert(15);
    heap.insert(25);
    heap.insert(7);

    cout<< "Heap elements: ";
    heap.print();

    cout<< "Extracted min: " << heap.extractMin() << endl;

    cout << "Heap after extraction: ";
    heap.print();

    return 0;
}