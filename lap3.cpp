#include <iostream>
using namespace std;

int steps = 0;

void towerOfHanoi(int n, char source, char dest, char aux) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << dest << endl;
        steps++;
        return;
    }
    towerOfHanoi(n - 1, source, aux, dest);
    cout << "Move disk " << n << " from " << source << " to " << dest << endl;
    steps++;
    towerOfHanoi(n - 1, aux, dest, source);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    towerOfHanoi(n, 'A', 'C', 'B');
    cout << "Total steps = " << steps << endl;
}

#include <iostream>
using namespace std;

int callCount = 0;

int fibonacci(int n) {
    callCount++;
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int result = fibonacci(n);
    cout << "Fibonacci number = " << result << endl;
    cout << "Total recursive calls = " << callCount << endl;
}


#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);       // Divide left
        mergeSort(arr, mid + 1, right);  // Divide right
        merge(arr, left, mid, right);    // Conquer (merge)
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nBefore Sorting:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    mergeSort(arr, 0, n - 1);

    cout << "\n\nAfter Sorting:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    delete[] arr;
    return 0;
}

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* result = nullptr;
    if (a->data <= b->data) {
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }
    return result;
}

void split(Node* source, Node** front, Node** back) {
    Node* slow = source;
    Node* fast = source->next;

    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = source;
    *back = slow->next;
    slow->next = nullptr;
}

void mergeSort(Node** headRef) {
    Node* head = *headRef;
    if (!head || !head->next)
        return;

    Node* a;
    Node* b;
    split(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef = merge(a, b);
}

void push(Node** head, int data) {
    Node* newNode = new Node{data, *head};
    *head = newNode;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    push(&head, 15);
    push(&head, 10);
    push(&head, 5);
    push(&head, 20);

    mergeSort(&head);
    printList(head);
}