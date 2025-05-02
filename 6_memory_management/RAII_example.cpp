/*
RAII stands for “Resource Acquisition Is Initialization”. Suppose there is a  “resource” in 
terms of Files, Memory, Sockets, etc. RAII means that an object’s creation and destruction are 
tied to a resource being acquired and released.
*/

#include <iostream>
#include <fstream>

class FileHandler {
private:
    std::ofstream file;

public:
    // Constructor acquires the resource
    FileHandler(const std::string& filename) {
        file.open(filename);
        if (file.is_open()) {
            std::cout << "File opened successfully.\n";
        } else {
            std::cerr << "Failed to open file.\n";
        }
    }

    // Write some data
    void write(const std::string& data) {
        if (file.is_open()) {
            file << data << std::endl;
        }
    }

    // Destructor releases the resource
    ~FileHandler() {
        if (file.is_open()) {
            file.close();
            std::cout << "File closed automatically in destructor.\n";
        }
    }
};

int main() {
    {
        FileHandler fh("example.txt");  // File is opened here
        fh.write("This is an example of RAII in C++.");  // Writing to file
    }  
    // FileHandler goes out of scope here => file is closed automatically
    //The constructor opens a file (acquires a resource).
    //The destructor ensures the file is closed (releases the resource) even if an exception occurs.
    //No need to manually call close(), which reduces the chance of resource leaks.

    std::cout << "Program continues...\n";
    return 0;
}
