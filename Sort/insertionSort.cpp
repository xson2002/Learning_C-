#include <iostream>
#include <vector>
#include <climits>
#include <chrono> // To calculate the time

using namespace std;
using namespace std::chrono;

void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int j = i;
        int tmp = arr[i];

        while (j > 0 && tmp < arr[j - 1]) {
            arr[j] = arr[j - 1];
            --j;
        }

        arr[j] = tmp;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    high_resolution_clock::time_point start = high_resolution_clock::now();
    int n;
    cin >> n; 

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    insertionSort(arr);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; 
    }
    cout << endl;

    high_resolution_clock::time_point end = high_resolution_clock::now();

    int duration = duration_cast<microseconds>(end - start).count();
    cout << duration << " milisecond" << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

// algorithm complexity O(N^2)