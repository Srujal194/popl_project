#include <iostream>
#include <fstream>
#include <thread>
#include <vector>

using namespace std;

void reader(const string& file_path, vector<string>& content) {
    ifstream input_file(file_path);
    if (!input_file.is_open()) {
        cerr << "Failed to open input file" << endl;
        return;
    }

    string line;
    while (getline(input_file, line)) {
        content.push_back(line);
        cout << "Read: " << line << endl;
    }
    input_file.close();

    cout << "Finished reading from file" << endl;
}

void writer(const string& file_path, const vector<string>& content) {
    ofstream output_file(file_path);
    if (!output_file.is_open()) {
        cerr << "Failed to create output file" << endl;
        return;
    }

    for (const string& line : content) {
        output_file << "Write: " << line << endl;
    }
    output_file.close();

    cout << "Finished writing to file" << endl;
}

int main() {
    string input_file_path = "input.txt";
    string output_file_path = "output.txt";
    vector<string> file_content;

    // Create threads for reading and writing
    thread reader_thread(reader, input_file_path, ref(file_content));
    reader_thread.join();
    thread writer_thread(writer, output_file_path, cref(file_content));
    writer_thread.join();

    return 0;
}
