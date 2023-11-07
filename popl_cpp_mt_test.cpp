#include <iostream>
#include <vector>
#include <thread>

void reader(const std::vector<int>& data) {
    for (int item : data) {
        std::cout << "Read: " << item << std::endl;
    }
}

void writer(const std::vector<int>& data) {
    for (int item : data) {
        std::cout << "Write: " << item * 2 << std::endl;
    }
}

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};

    // Create threads for reading and writing
    std::thread reader_thread(reader, data);
    std::thread writer_thread(writer, data);

    // Wait for both threads to finish
    reader_thread.join();
    writer_thread.join();

    return 0;
}