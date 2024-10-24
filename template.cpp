#include <iostream>
#include <chrono> // To calculate the time

using namespace std;
using namespace std::chrono;


int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    high_resolution_clock::time_point start = high_resolution_clock::now();


    high_resolution_clock::time_point end = high_resolution_clock::now();

    int duration = duration_cast<microseconds>(end - start).count();
    cout << duration << " milisecond" << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
