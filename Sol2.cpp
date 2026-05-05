//Array Transformation Cost Minimization
#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& A, int K) {
    int n = A.size();

    // Check feasibility
    for (int i = 1; i < n; i++) {
        if ((A[i] - A[0]) % K != 0)
            return -1;
    }

    // Normalize
    vector<int> B(n);
    for (int i = 0; i < n; i++)
        B[i] = A[i] / K;

    // Sort to find median
    sort(B.begin(), B.end());
    int median = B[n / 2];

    // Calculate operations
    int ops = 0;
    for (int i = 0; i < n; i++)
        ops += abs(B[i] - median);

    return ops;
}

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int K;
    cin >> K;

    cout << minOperations(A, K);
}
