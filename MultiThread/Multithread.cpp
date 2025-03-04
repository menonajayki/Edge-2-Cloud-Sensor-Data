#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>

class Worker {
public:
    // Constructor: each Worker gets a unique ID.
    Worker(int id) : id(id) {}

    // Function that each thread will run.
    void doWork() {
        // Simulate processing several tasks.
        for (int i = 0; i < 5; ++i) {
            {
                // Lock mutex to protect std::cout from simultaneous access.
                std::lock_guard<std::mutex> guard(coutMutex);
                std::cout << "Worker " << id << " is processing task " << i << std::endl;
            }
            // Simulate time-consuming task.
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

private:
    int id;  // Unique identifier for each worker.
    static std::mutex coutMutex;  // Shared mutex for synchronized console output.
};

// Define the static mutex outside the class.
std::mutex Worker::coutMutex;

int main() {
    const int numWorkers = 4;  // For example, create 4 worker objects.
    std::vector<Worker> workers;
    std::vector<std::thread> threads;

    // Create Worker objects.
    for (int i = 0; i < numWorkers; ++i) {
        workers.emplace_back(i + 1);
    }

    // Launch a thread for each Worker, calling its doWork member function.
    for (auto& worker : workers) {
        // Pass the address of the worker object.
        threads.emplace_back(&Worker::doWork, &worker);
    }

    // Wait for all threads to complete.
    for (auto& t : threads) {
        t.join();
    }

    std::cout << "All workers have completed their tasks." << std::endl;
    return 0;
}
