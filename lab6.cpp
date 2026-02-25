#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start, finish;
};

bool cmp(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int n;
    cin >> n;

    vector<Activity> act(n);
    for (int i = 0; i < n; i++)
        cin >> act[i].start >> act[i].finish;

    sort(act.begin(), act.end(), cmp);

    int count = 1;
    int lastFinish = act[0].finish;

    for (int i = 1; i < n; i++) {
        if (act[i].start >= lastFinish) {
            count++;
            lastFinish = act[i].finish;
        }
    }

    cout << "Maximum number of activities: " << count;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n), dep(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) cin >> dep[i];

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int platforms = 1, maxPlatforms = 1;
    int i = 1, j = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms++;
            maxPlatforms = max(maxPlatforms, platforms);
            i++;
        } else {
            platforms--;
            j++;
        }
    }

    cout << "Minimum platforms required: " << maxPlatforms;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
};

bool cmp(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

int main() {
    int n, W;
    cin >> n >> W;

    vector<Item> items(n);
    for (int i = 0; i < n; i++)
        cin >> items[i].value >> items[i].weight;

    sort(items.begin(), items.end(), cmp);

    double maxValue = 0.0;

    for (int i = 0; i < n && W > 0; i++) {
        if (items[i].weight <= W) {
            W -= items[i].weight;
            maxValue += items[i].value;
        } else {
            maxValue += items[i].value * ((double)W / items[i].weight);
            W = 0;
        }
    }

    cout << "Maximum value: " << maxValue;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

struct Job {
    int deadline, profit;
};

bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int n;
    cin >> n;

    vector<Job> jobs(n);
    for (int i = 0; i < n; i++)
        cin >> jobs[i].deadline >> jobs[i].profit;

    sort(jobs.begin(), jobs.end(), cmp);

    int maxDeadline = 0;
    for (auto j : jobs)
        maxDeadline = max(maxDeadline, j.deadline);

    vector<int> slot(maxDeadline + 1, -1);

    int count = 0, totalProfit = 0;

    for (auto job : jobs) {
        for (int t = job.deadline; t > 0; t--) {
            if (slot[t] == -1) {
                slot[t] = job.profit;
                count++;
                totalProfit += job.profit;
                break;
            }
        }
    }

    cout << "Jobs done: " << count << endl;
    cout << "Maximum profit: " << totalProfit;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct cmp {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string code) {
    if (!root) return;

    if (root->ch != '$')
        cout << root->ch << " : " << code << endl;

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    int n;
    cin >> n;

    vector<char> chars(n);
    vector<int> freq(n);

    for (int i = 0; i < n; i++) cin >> chars[i];
    for (int i = 0; i < n; i++) cin >> freq[i];

    priority_queue<Node*, vector<Node*>, cmp> pq;

    for (int i = 0; i < n; i++)
        pq.push(new Node(chars[i], freq[i]));

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* merged = new Node('$', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        pq.push(merged);
    }

    cout << "Huffman Codes:\n";
    printCodes(pq.top(), "");
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

struct Customer {
    int arrival, departure;
};

bool cmp(Customer a, Customer b) {
    return a.departure < b.departure;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<Customer>> comp(K + 1);

    for (int i = 0; i < N; i++) {
        int a, d, p;
        cin >> a >> d >> p;
        comp[p].push_back({a, d});
    }

    int totalServed = 0;

    for (int i = 1; i <= K; i++) {
        auto &v = comp[i];
        if (v.empty()) continue;

        sort(v.begin(), v.end(), cmp);

        int lastEnd = -1;
        for (auto c : v) {
            if (c.arrival >= lastEnd) {
                totalServed++;
                lastEnd = c.departure;
            }
        }
    }

    cout << "Maximum customers served: " << totalServed;
    return 0;
}

