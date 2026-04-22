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



#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int p, q, r;
    cin >> p >> q >> r;

    int total = p + q + r;

    if (max({p, q, r}) > (total + 1) / 2) {
        cout << "Not Possible!" << endl;
        return 0;
    }

    priority_queue<pair<int,char>> pq;
    if (p > 0) pq.push({p, 'P'});
    if (q > 0) pq.push({q, 'Q'});
    if (r > 0) pq.push({r, 'R'});

    string result = "";
    char last = '#'; 

    while (!pq.empty()) {
        auto [cnt1, ball1] = pq.top(); pq.pop();

        if (ball1 != last) {
            result += ball1;
            last = ball1;
            if (cnt1 - 1 > 0) pq.push({cnt1 - 1, ball1});
        } else {
            if (pq.empty()) {
                cout << "Not Possible!" << endl;
                return 0;
            }
            auto [cnt2, ball2] = pq.top(); pq.pop();
            result += ball2;
            last = ball2;
            if (cnt2 - 1 > 0) pq.push({cnt2 - 1, ball2});
            pq.push({cnt1, ball1}); 
        }
    }

    cout << "Arrangement: " << result << endl;
    cout << "Length: " << result.size() << endl;
    return 0;
}




#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int>& pos, int k, int dist) {
    int count = 1;
    int last = pos[0];

    for (int i = 1; i < pos.size(); i++) {
        if (pos[i] - last >= dist) {
            count++;
            last = pos[i];
        }
        if (count >= k) return true;
    }
    return false;
}

int maxMinDistance(vector<int>& pos, int k) {
    sort(pos.begin(), pos.end());

    int low = 1;
    int high = pos.back() - pos[0];
    int ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPlace(pos, k, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n;          
    vector<int> pos(n);

    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }

    cin >> k;          

    cout << maxMinDistance(pos, k) << endl;

    return 0;
}