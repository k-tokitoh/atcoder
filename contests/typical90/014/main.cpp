#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long N;
  cin >> N;

  vector< long long > A(N);

  for (long long i = 0; i < N; i++) {
    long long a;
    cin >> a;
    A[i] = a;
  }

  sort(A.begin(), A.end());

  vector< long long > B(N);

  for (long long i = 0; i < N; i++) {
    long long b;
    cin >> b;
    B[i] = b;
  }

  sort(B.begin(), B.end());

  long long e = 0;

  for (long long i = 0; i < N; i++) {
    e += abs(A[i] - B[i]);
  }

  cout << e << endl;

  return 0;
}
