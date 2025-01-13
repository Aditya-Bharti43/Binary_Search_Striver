#include <bits/stdc++.h>
using namespace std;

void findAllPeaks(vector<int>& arr, int l, int h, vector<int>& peaks) {
    if (l > h) return;

    int mid = l + (h - l) / 2;

    // Check if mid is a peak
    if ((mid == 0 || arr[mid] > arr[mid - 1]) &&
        (mid == arr.size() - 1 || arr[mid] > arr[mid + 1])) {
        peaks.push_back(mid);
    }

    // Recursively check the left and right halves
    findAllPeaks(arr, l, mid - 1, peaks);
    findAllPeaks(arr, mid + 1, h, peaks);
}

vector<int> findAllPeaks(vector<int>& arr) {
    vector<int> peaks;
    findAllPeaks(arr, 0, arr.size() - 1, peaks);
    return peaks;
}

int main() {
    vector<int> arr = {1, 3, 2, 4, 1, 5};
    vector<int> peaks = findAllPeaks(arr);

    cout << "Peaks found at indices: ";
    for (int peak : peaks) {
        cout << peak << " ";
    }
    cout << endl;

    return 0;
}
