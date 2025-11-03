
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

class Timer {
    high_resolution_clock::time_point start_time;
public:
    void start() { start_time = high_resolution_clock::now(); }
    double stop() {
        auto end_time = high_resolution_clock::now();
        return duration<double>(end_time - start_time).count();
    }
};

int main() {
    Timer timer;
    timer.start();
    for (volatile int i = 0; i < 1000000; i++);
    cout << "Execution time: " << timer.stop() << " s" << endl;
    return 0;
}
