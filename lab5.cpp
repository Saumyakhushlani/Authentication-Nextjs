#include <iostream>
using namespace std;

void multiply(int A[2][2], int B[2][2], int C[2][2]) {
    C[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0];
    C[0][1] = A[0][0]*B[0][1] + A[0][1]*B[1][1];
    C[1][0] = A[1][0]*B[0][0] + A[1][1]*B[1][0];
    C[1][1] = A[1][0]*B[0][1] + A[1][1]*B[1][1];
}

int main() {
    int A[2][2] = {{1,2},{3,4}};
    int B[2][2] = {{5,6},{7,8}};
    int C[2][2];

    multiply(A, B, C);

    cout << "Result Matrix:\n";
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++)
            cout << C[i][j] << " ";
        cout << endl;
    }
    return 0;
}


#include <iostream>
#include <string>
using namespace std;

string addStrings(string a, string b) {
    string result = "";
    int carry = 0, i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result = char(sum % 10 + '0') + result;
        carry = sum / 10;
    }
    return result;
}

string multiply(string x, string y) {
    int n = x.size();
    if (n == 1)
        return to_string((x[0] - '0') * (y[0] - '0'));

    int mid = n / 2;
    string a = x.substr(0, mid);
    string b = x.substr(mid);
    string c = y.substr(0, mid);
    string d = y.substr(mid);

    string ac = multiply(a, c);
    string bd = multiply(b, d);
    string ad = multiply(a, d);
    string bc = multiply(b, c);

    string result = ac;
    for (int i = 0; i < n; i++) result += "0";

    string middle = addStrings(ad, bc);
    for (int i = 0; i < mid; i++) middle += "0";

    return addStrings(addStrings(result, middle), bd);
}

int main() {
    string x = "1234";
    string y = "5678";

    cout << "Product = " << multiply(x, y) << endl;
    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;

Matrix add(Matrix A, Matrix B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

Matrix subtract(Matrix A, Matrix B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

Matrix strassen(Matrix A, Matrix B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));

    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int k = n / 2;
    Matrix A11(k, vector<int>(k)), A12(k, vector<int>(k)),
           A21(k, vector<int>(k)), A22(k, vector<int>(k));
    Matrix B11(k, vector<int>(k)), B12(k, vector<int>(k)),
           B21(k, vector<int>(k)), B22(k, vector<int>(k));

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }

    Matrix M1 = strassen(add(A11, A22), add(B11, B22));
    Matrix M2 = strassen(add(A21, A22), B11);
    Matrix M3 = strassen(A11, subtract(B12, B22));
    Matrix M4 = strassen(A22, subtract(B21, B11));
    Matrix M5 = strassen(add(A11, A12), B22);
    Matrix M6 = strassen(subtract(A21, A11), add(B11, B12));
    Matrix M7 = strassen(subtract(A12, A22), add(B21, B22));

    Matrix C11 = add(subtract(add(M1, M4), M5), M7);
    Matrix C12 = add(M3, M5);
    Matrix C21 = add(M2, M4);
    Matrix C22 = add(subtract(add(M1, M3), M2), M6);

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }

    return C;
}

int main() {
    int n = 2; // dynamic
    Matrix A = {{1, 2}, {3, 4}};
    Matrix B = {{5, 6}, {7, 8}};

    Matrix C = strassen(A, B);

    cout << "Result Matrix:\n";
    for (auto row : C) {
        for (auto val : row)
            cout << val << " ";
        cout << endl;
    }
    return 0;
}