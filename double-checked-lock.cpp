#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

class Singleton {
public:
    static Singleton* getInstance() {
        // First check (no locking)
        if (instance == nullptr) {
            mtx.lock(); // Lock the mutex manually
            // Second check (after acquiring the lock)
            if (instance == nullptr) {
                instance = new Singleton();
                std::cout << "Singleton instance created by thread: " << std::this_thread::get_id() << "\n";
            }
            mtx.unlock(); // Unlock the mutex manually
        }
        return instance;
    }

    void display() const {
        std::cout << "Singleton instance address: " << this << "\n";
    }

private:
    Singleton() = default;                 // Private constructor
    ~Singleton() = default;                // Private destructor
    Singleton(const Singleton&) = delete;  // Disable copy constructor
    Singleton& operator=(const Singleton&) = delete; // Disable assignment

    static Singleton* instance;  // Pointer to the singleton instance
    static std::mutex mtx;       // Mutex for synchronization
};

// Static member initialization
Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mtx;

// Function that threads will run
void accessSingleton() {
    Singleton* instance = Singleton::getInstance();
    instance->display();
}

int main() {
    const int THREAD_COUNT = 50; // Simulate high contention with many threads
    std::vector<std::thread> threads;

    // Launch multiple threads
    for (int i = 0; i < THREAD_COUNT; ++i) {
        threads.emplace_back(accessSingleton);
    }

    // Wait for all threads to complete
    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
