#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    if (N < 2) {
        cout << "No primes\n";
        return 0;
    }

    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= N; p++) {
        if (isPrime[p]) {
            // mark multiples of p starting from p*p
            for (int j = p * p; j <= N; j += p) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) cout << i << " ";
    }
    cout << "\n";

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> oddMagic(int n) {
    vector<vector<int>> magic(n, vector<int>(n, 0));
    int i = 0, j = n / 2;

    for (int num = 1; num <= n * n; num++) {
        magic[i][j] = num;
        int ni = (i - 1 + n) % n;
        int nj = (j + 1) % n;

        if (magic[ni][nj] != 0) i = (i + 1) % n;
        else { i = ni; j = nj; }
    }
    return magic;
}

vector<vector<int>> doublyEvenMagic(int n) {
    vector<vector<int>> magic(n, vector<int>(n, 0));
    int num = 1;

    // fill normally
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            magic[i][j] = num++;

    // invert specific cells
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i % 4 == j % 4) || ((i % 4) + (j % 4) == 3)) {
                magic[i][j] = n * n + 1 - magic[i][j];
            }
        }
    }

    return magic;
}

// Strachey method for singly even (n = 4k + 2)
vector<vector<int>> singlyEvenMagic(int n) {
    int half = n / 2;
    int subSize = half * half;

    // make odd magic square of size half
    vector<vector<int>> sub = oddMagic(half);

    vector<vector<int>> magic(n, vector<int>(n, 0));

    // fill 4 blocks
    // A B
    // C D
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            int val = sub[i][j];
            magic[i][j] = val;                       // A
            magic[i][j + half] = val + 2 * subSize;  // B
            magic[i + half][j] = val + 3 * subSize;  // C
            magic[i + half][j + half] = val + subSize; // D
        }
    }

    int k = (n - 2) / 4;

    // swap columns
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < k; j++) {
            swap(magic[i][j], magic[i + half][j]);
        }
    }

    for (int i = 0; i < half; i++) {
        for (int j = n - k + 1; j < n; j++) {
            swap(magic[i][j - half], magic[i + half][j - half]);
        }
    }

    // special central swap
    swap(magic[k][0], magic[k + half][0]);
    swap(magic[k][k], magic[k + half][k]);

    return magic;
}

int main() {
    int n;
    cin >> n;

    if (n < 3) {
        cout << "Magic square not possible for n < 3\n";
        return 0;
    }

    vector<vector<int>> magic;

    if (n % 2 == 1) {
        magic = oddMagic(n);
    } else if (n % 4 == 0) {
        magic = doublyEvenMagic(n);
    } else {
        magic = singlyEvenMagic(n);
    }

    // print
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << magic[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
