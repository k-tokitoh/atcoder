#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  long long P, Q;
  cin >> N >> P >> Q;

  vector< long long > A(N);

  for (int i; i < N; i++) {
    int a;
    cin >> a;
    A[i] = a % P;
  }

  int ans = 0;

  for (int i = 0; i < N - 4; i++) {
    long long r1 = A[i] % P;
    for (int j = i + 1; j < N - 3; j++) {
      long long r2 = r1 * A[j] % P;
      for (int k = j + 1; k < N - 2; k++) {
        long long r3 = r2 * A[k] % P;
        for (int l = k + 1; l < N - 1; l++) {
          long long r4 = r3 * A[l] % P;
          for (int m = l + 1; m < N; m++) {
            long long r5 = r4 * A[m] % P;
            if (r5 == Q) {
              ans++;
            }
          }
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}
