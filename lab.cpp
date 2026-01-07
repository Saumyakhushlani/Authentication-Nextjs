#include <iostream>
using namespace std;

int insertElement(int arr[], int n, int x, int pos) {
    for (int i = n; i > pos; i--) arr[i] = arr[i-1];
    arr[pos] = x;
    return n + 1;
}

int deleteElement(int arr[], int n, int pos) {
    for (int i = pos; i < n-1; i++) arr[i] = arr[i+1];
    return n - 1;
}

void traverse(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void reverseArray(int arr[], int n) {
    int i=0,j=n-1;
    while(i<j) swap(arr[i++],arr[j--]);
}

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) if (arr[i] == x) return i;
    return -1;
}

int binarySearch(int arr[], int n, int x) {
    int l=0,r=n-1;
    while(l<=r){
        int m=(l+r)/2;
        if(arr[m]==x) return m;
        else if(arr[m]<x) l=m+1;
        else r=m-1;
    }
    return -1;
}

int mergeArrays(int a[], int n1, int b[], int n2, int c[]) {
    for(int i=0;i<n1;i++) c[i]=a[i];
    for(int i=0;i<n2;i++) c[n1+i]=b[i];
    return n1+n2;
}

int main() {
    int arr[100] = {3,5,7,9,11};
    int n = 5;

    n = insertElement(arr, n, 20, 2);
    n = deleteElement(arr, n, 4);

    traverse(arr, n);

    reverseArray(arr, n);
    traverse(arr, n);

    int b[5] = {1,2,4,6,8};
    int c[200];
    int m = mergeArrays(arr, n, b, 5, c);
    traverse(c, m);

    cout << linearSearch(arr, n, 7) << endl;
    cout << binarySearch(b, 5, 6) << endl;
}


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insertSLL(Node* head, int x) {
    Node* p = new Node{x, head};
    return p;
}

Node* deleteSLL(Node* head, int x) {
    if (!head) return head;
    if (head->data == x) return head->next;
    Node* cur = head;
    while (cur->next && cur->next->data != x) cur = cur->next;
    if (cur->next) cur->next = cur->next->next;
    return head;
}

int searchSLL(Node* head, int x) {
    int i=0;
    while (head) {
        if (head->data == x) return i;
        head = head->next;
        i++;
    }
    return -1;
}

void printSLL(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

struct DNode {
    int data;
    DNode *prev, *next;
};

DNode* insertDLL(DNode* head, int x) {
    DNode* p = new DNode{x, nullptr, head};
    if (head) head->prev = p;
    return p;
}

void printDLL(DNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

struct CNode {
    int data;
    CNode* next;
};

CNode* insertCLL(CNode* tail, int x) {
    CNode* p = new CNode{x, nullptr};
    if (!tail) {
        p->next = p;
        return p;
    }
    p->next = tail->next;
    tail->next = p;
    return p;
}

void printCLL(CNode* tail) {
    if (!tail) return;
    CNode* cur = tail->next;
    do {
        cout << cur->data << " ";
        cur = cur->next;
    } while (cur != tail->next);
    cout << endl;
}

int main() {
    Node* s = nullptr;
    s = insertSLL(s, 3);
    s = insertSLL(s, 2);
    s = insertSLL(s, 1);
    s = deleteSLL(s, 2);
    printSLL(s);
    cout << searchSLL(s, 3) << endl;

    DNode* d = nullptr;
    d = insertDLL(d, 10);
    d = insertDLL(d, 20);
    d = insertDLL(d, 30);
    printDLL(d);

    CNode* c = nullptr;
    c = insertCLL(c, 5);
    c = insertCLL(c, 6);
    c = insertCLL(c, 7);
    printCLL(c);
}


// Stack Array
#include <iostream>
using namespace std;

int s[50];
int top = -1;

void push(int x) {
    top = top + 1;
    s[top] = x;
}

int pop() {
    int v = s[top];
    top = top - 1;
    return v;
}

int main() {
    push(10);
    push(20);

    int a = pop();
    cout << a << endl;

    return 0;
}


// Stack LinkedList
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* push(Node* head, int x) {
    Node* p = new Node;
    p->data = x;
    p->next = head;
    head = p;
    return head;
}

Node* pop(Node* head) {
    head = head->next;
    return head;
}

int main() {
    Node* head = nullptr;

    head = push(head, 5);
    head = push(head, 9);

    head = pop(head);

    cout << head->data << endl;

    return 0;
}


// Queue
#include <iostream>
using namespace std;

int q[50];
int f = 0;
int r = -1;

void enqueue(int x) {
    r = r + 1;
    q[r] = x;
}

int dequeue() {
    int v = q[f];
    f = f + 1;
    return v;
}

int main() {
    enqueue(1);
    enqueue(2);

    int a = dequeue();
    cout << a << endl;

    return 0;
}


// Circular Queue
#include <iostream>
using namespace std;

int cq[5];
int f = 0;
int r = 0;
int cnt = 0;

void enqueue(int x) {
    cq[r] = x;
    r = (r + 1) % 5;
    cnt = cnt + 1;
}

int dequeue() {
    int v = cq[f];
    f = (f + 1) % 5;
    cnt = cnt - 1;
    return v;
}

int main() {
    enqueue(7);
    enqueue(8);

    int a = dequeue();
    cout << a << endl;

    return 0;
}

#include <iostream>
using namespace std;

int dq[50];
int f = 0;
int r = -1;

void pushFront(int x) {
    f = f - 1;
    dq[f] = x;
}

void pushBack(int x) {
    r = r + 1;
    dq[r] = x;
}

int popFront() {
    int v = dq[f];
    f = f + 1;
    return v;
}

int popBack() {
    int v = dq[r];
    r = r - 1;
    return v;
}

int main() {
    f = 0;
    r = -1;

    pushBack(4);
    pushFront(2);

    int a = popFront();
    cout << a << endl;

    return 0;
}
