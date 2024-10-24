#include <iostream>
#include <vector>
#include <climits>
#include <chrono> // To calculate the time

using namespace std;
using namespace std::chrono;
vector<int> a(1000);

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }
    
    int n = arr.size();

    if (arr.size() == 1) {
        return ;
    }
    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);


    int i = left, j = mid + 1; 
    int cur = 0; 

    while (i <= mid || j <= right) { 
        if (i > mid) {
            a[cur++] = arr[j++];
        } else if (j > right) {
            a[cur++] = arr[i++];
        } else if (arr[i] < arr[j]) {
            a[cur++] = arr[i++];
        } else {
            a[cur++] = arr[j++];
        }
    }

    // copy mảng a về mảng arr
    for (int i = 0; i < cur; i++)
        arr[left + i] = a[i];
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

    mergeSort(arr, 0, n-1);

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