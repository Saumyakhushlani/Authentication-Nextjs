#include <bits/stdc++.h>
using namespace std;

// 🔹 Binary Search
int binarySearch(vector<int>& arr, int l, int r, int key) {
    if (l > r) return -1;

    int mid = l + (r - l) / 2;

    if (arr[mid] == key) return mid;
    else if (key < arr[mid])
        return binarySearch(arr, l, mid - 1, key);
    else
        return binarySearch(arr, mid + 1, r, key);
}

// 🔹 Ternary Search
int ternarySearch(vector<int>& arr, int l, int r, int key) {
    if (l > r) return -1;

    int mid1 = l + (r - l) / 3;
    int mid2 = r - (r - l) / 3;

    if (arr[mid1] == key) return mid1;
    if (arr[mid2] == key) return mid2;

    if (key < arr[mid1])
        return ternarySearch(arr, l, mid1 - 1, key);
    else if (key > arr[mid2])
        return ternarySearch(arr, mid2 + 1, r, key);
    else
        return ternarySearch(arr, mid1 + 1, mid2 - 1, key);
}

// 🔹 Quaternary Search
int quaternarySearch(vector<int>& arr, int l, int r, int key) {
    if (l > r) return -1;

    int m1 = l + (r - l) / 4;
    int m2 = l + (r - l) / 2;
    int m3 = l + 3 * (r - l) / 4;

    if (arr[m1] == key) return m1;
    if (arr[m2] == key) return m2;
    if (arr[m3] == key) return m3;

    if (key < arr[m1])
        return quaternarySearch(arr, l, m1 - 1, key);
    else if (key < arr[m2])
        return quaternarySearch(arr, m1 + 1, m2 - 1, key);
    else if (key < arr[m3])
        return quaternarySearch(arr, m2 + 1, m3 - 1, key);
    else
        return quaternarySearch(arr, m3 + 1, r, key);
}

int main() {
    // Dummy sorted vector
    vector<int> arr;
    for (int i = 1; i <= 100; i++) {
        arr.push_back(i * 2);   // 2,4,6,...200
    }

    int key = 142;

    int idx1 = binarySearch(arr, 0, arr.size() - 1, key);
    int idx2 = ternarySearch(arr, 0, arr.size() - 1, key);
    int idx3 = quaternarySearch(arr, 0, arr.size() - 1, key);

    cout << "Binary Search Index: " << idx1 << endl;
    cout << "Ternary Search Index: " << idx2 << endl;
    cout << "Quaternary Search Index: " << idx3 << endl;

    return 0;
}
