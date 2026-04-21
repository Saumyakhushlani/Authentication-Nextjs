#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int start, finish, weight;
};

int n;
vector<Job> jobs;
vector<int> dp;

int lastCompatible(int j) {
    for (int i = j - 1; i >= 0; i--)
        if (jobs[i].finish <= jobs[j].start)
            return i;
    return -1;
}

int main() {
    cin >> n;
    jobs.resize(n);

    for (int i = 0; i < n; i++)
        cin >> jobs[i].start >> jobs[i].finish >> jobs[i].weight;

    sort(jobs.begin(), jobs.end(), [](Job a, Job b) {
        return a.finish < b.finish;
    });

    dp.resize(n);
    for (int j = 0; j < n; j++) {
        int p = lastCompatible(j);
        int include = jobs[j].weight + (p >= 0 ? dp[p] : 0);
        int exclude = (j > 0 ? dp[j - 1] : 0);
        dp[j] = max(include, exclude);
    }

    cout << "Maximum Weight = " << dp[n - 1] << endl;
    return 0;
}




#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

// Recursive merge sort
void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;

    int mid = (low + high) / 2;

    mergeSort(arr, low, mid);        
    mergeSort(arr, mid + 1, high);   
    merge(arr, low, mid, high);      
}

int main() {
    vector<int> arr = {5, 3, 8, 4, 2, 7, 1, 10};

    mergeSort(arr, 0, arr.size() - 1);

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}




#include <bits/stdc++.h>
using namespace std;

// Partition function
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];   
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) i++;
        while (arr[j] > pivot && j >= low + 1) j--;

        if (i < j) swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]); 
    return j;
}

// Quick Sort function
void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);

        quickSort(arr, low, pIndex - 1);   
        quickSort(arr, pIndex + 1, high);  
    }
}

int main() {
    vector<int> arr = {5, 3, 8, 4, 2, 7, 1, 10};

    quickSort(arr, 0, arr.size() - 1);

    for (int x : arr) cout << x << " ";

    return 0;
}