#include <iostream>
#include <vector>

using namespace std;

class BinaryHeap {
private:
    vector<int> heap;

    // Get parent index
    int parent(int i) { return (i - 1) / 2; }

    // Get left child index
    int leftChild(int i) { return 2 * i + 1; }

    // Get right child index
    int rightChild(int i) { return 2 * i + 2; }

    // Sift-up (used when inserting)
    void siftUp(int i) {
        while (i > 0 && heap[parent(i)] > heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    // Sift-down (used in extractMin)
    void siftDown(int i) {
        int minIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < heap.size() && heap[left] < heap[minIndex])
            minIndex = left;

        if (right < heap.size() && heap[right] < heap[minIndex])
            minIndex = right;

        if (i != minIndex) {
            swap(heap[i], heap[minIndex]);
            siftDown(minIndex);
        }
    }

public:
    // Insert a new value into the heap
    void insert(int value) {
        heap.push_back(value);
        siftUp(heap.size() - 1);
    }

    // Extract the minimum element (root)
    int extractMin() {
        if (heap.empty()) {
            cerr << "Heap is empty!\n";
            return -1;
        }
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        siftDown(0);
        return minVal;
    }

    // Build a heap from an array
    void buildHeap(vector<int> &arr) {
        heap = arr;
        for (int i = (heap.size() / 2) - 1; i >= 0; i--) {
            siftDown(i);
        }
    }

    // Print heap elements
    void printHeap() {
        for (int val : heap)
            cout << val << " ";
        cout << "\n";
    }
};

// Driver function to test the heap
int main() {
    BinaryHeap heap;
    
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(30);
    heap.insert(15);
    heap.insert(25);
    heap.insert(7);

    cout << "Heap elements: ";
    heap.printHeap();

    cout << "Extracted min: " << heap.extractMin() << "\n";
    cout << "Heap after extraction: ";
    heap.printHeap();

    vector<int> arr = {40, 10, 50, 20, 60, 30};
    heap.buildHeap(arr);
    cout << "Heap after buildHeap: ";
    heap.printHeap();

    return 0;
}
