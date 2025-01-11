#include <iostream>
#include <unistd.h> // Required for fork()
using namespace std;

int main() {
    pid_t pid = fork(); // Create a child process

    if (pid < 0) {
        // Error in creating the process
        cerr << "Fork failed!" << endl;
    } else {
        // Both the parent and child process execute this block
        cout << "helloe" << endl;
    }

    return 0;
}
