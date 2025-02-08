#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Node {
public:
    int key, degree;
    bool marked;
    Node* parent;
    Node* child;
    Node* next;
    Node* prev;

    Node(int value) : key(value), degree(0), marked(false), parent(nullptr), child(nullptr), next(this), prev(this) {}
};

class FibonacciHeap {
private:
    Node* minNode;
    int nodeCount;

    // Merges two circular doubly linked lists
    void mergeLists(Node* a, Node* b) {
        if (!a || !b) return;
        Node* aNext = a->next;
        Node* bPrev = b->prev;
        a->next = b;
        b->prev = a;
        aNext->prev = bPrev;
        bPrev->next = aNext;
    }

    // Links two trees of the same degree
    void link(Node* y, Node* x) {
        y->prev->next = y->next;
        y->next->prev = y->prev;

        y->parent = x;
        y->marked = false;

        if (!x->child) {
            x->child = y;
            y->next = y;
            y->prev = y;
        } else {
            mergeLists(x->child, y);
        }

        x->degree++;
    }

    // Consolidate trees of the same degree
    void consolidate() {
        if (!minNode) return;

        int maxDegree = log2(nodeCount) + 1;
        vector<Node*> degreeTable(maxDegree, nullptr);
        
        vector<Node*> rootList;
        Node* start = minNode;
        Node* x = start;
        do {
            rootList.push_back(x);
            x = x->next;
        } while (x != start);

        for (Node* x : rootList) {
            int d = x->degree;
            while (degreeTable[d]) {
                Node* y = degreeTable[d];
                if (x->key > y->key) swap(x, y);
                link(y, x);
                degreeTable[d] = nullptr;
                d++;
            }
            degreeTable[d] = x;
        }

        minNode = nullptr;
        for (Node* node : degreeTable) {
            if (node) {
                if (!minNode || node->key < minNode->key) {
                    minNode = node;
                }
            }
        }
    }

public:
    FibonacciHeap() : minNode(nullptr), nodeCount(0) {}

    // Insert a new value
    void insert(int key) {
        Node* newNode = new Node(key);
        if (!minNode) {
            minNode = newNode;
        } else {
            mergeLists(minNode, newNode);
            if (key < minNode->key) {
                minNode = newNode;
            }
        }
        nodeCount++;
    }

    // Get the minimum value
    int getMin() {
        return minNode ? minNode->key : -1;
    }

    // Extract the minimum value
    int extractMin() {
        if (!minNode) return -1;

        Node* oldMin = minNode;
        int minValue = oldMin->key;

        if (oldMin->child) {
            Node* child = oldMin->child;
            do {
                child->parent = nullptr;
                child = child->next;
            } while (child != oldMin->child);
            mergeLists(minNode, oldMin->child);
        }

        if (oldMin->next == oldMin) {
            minNode = nullptr;
        } else {
            minNode = oldMin->next;
            oldMin->prev->next = oldMin->next;
            oldMin->next->prev = oldMin->prev;
            consolidate();
        }

        nodeCount--;
        delete oldMin;
        return minValue;
    }

    // Merge another Fibonacci heap into this one
    void merge(FibonacciHeap& other) {
        if (!other.minNode) return;
        if (!minNode) {
            minNode = other.minNode;
        } else {
            mergeLists(minNode, other.minNode);
            if (other.minNode->key < minNode->key) {
                minNode = other.minNode;
            }
        }
        nodeCount += other.nodeCount;
        other.minNode = nullptr;
        other.nodeCount = 0;
    }

    // Decrease a key (for simplicity, finds first match)
    void decreaseKey(Node* node, int newKey) {
        if (!node || newKey > node->key) return;
        node->key = newKey;

        Node* parent = node->parent;
        if (parent && node->key < parent->key) {
            cut(node, parent);
            cascadingCut(parent);
        }

        if (node->key < minNode->key) {
            minNode = node;
        }
    }

    // Deletes a node (decrease key to -∞, then extract min)
    void deleteKey(Node* node) {
        decreaseKey(node, -1e9);
        extractMin();
    }

private:
    void cut(Node* child, Node* parent) {
        if (child->next == child) {
            parent->child = nullptr;
        } else {
            child->prev->next = child->next;
            child->next->prev = child->prev;
            if (parent->child == child) {
                parent->child = child->next;
            }
        }
        parent->degree--;

        mergeLists(minNode, child);
        child->parent = nullptr;
        child->marked = false;
    }

    void cascadingCut(Node* node) {
        Node* parent = node->parent;
        if (parent) {
            if (!node->marked) {
                node->marked = true;
            } else {
                cut(node, parent);
                cascadingCut(parent);
            }
        }
    }
};

// Test Fibonacci Heap
int main() {
    FibonacciHeap heap;
    
    heap.insert(10);
    heap.insert(5);
    heap.insert(15);
    heap.insert(20);

    cout << "Minimum: " << heap.getMin() << "\n";
    
    cout << "Extracted Min: " << heap.extractMin() << "\n";
    cout << "New Minimum: " << heap.getMin() << "\n";

    return 0;
}
