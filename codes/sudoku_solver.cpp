#include <iostream>
#include <algorithm>

using namespace std;

class TrafficJamCounter {
private:
    string cars;
    int count;
    bool isValidArrangement() const {
        return adjacent_find(cars.begin(), cars.end()) == cars.end();
    }
public:
    TrafficJamCounter() : cars("ABC"), count(0) {}
    void countArrangements() {
        do {
            if (isValidArrangement()) {
                count++;
            }
        } while (next_permutation(cars.begin(), cars.end()));
    }
    int getResult() const {
        return count;
    }
};

int main() {
    TrafficJamCounter counter;
    counter.countArrangements();

    // Output the result
    cout << "Number of ways three cars can be arranged in a traffic jam: " << counter.getResult() << endl;

    return 0;
}
