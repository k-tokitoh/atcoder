#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  long long N, Q;
  cin >> N >> Q;

  vector< long long > A(N);

  for (long long i = 0; i < N; i++) {
    cin >> A[i];
  }

  vector< long long > diff(N - 1);

  long long ans = 0;

  for (long long i = 0; i < N - 1; i++) {
    diff[i] = A[i + 1] - A[i];
    ans += abs(diff[i]);
  }

  for (long long i = 0; i < Q; i++) {
    long long l, r, v;
    cin >> l >> r >> v;

    if (1 < l) {
      long long before = abs(diff[l - 2]);
      diff[l - 2] += v;
      long long after = abs(diff[l - 2]);
      ans += after - before;
    }
    if (r < N) {
      long long before = abs(diff[r - 1]);
      diff[r - 1] -= v;
      long long after = abs(diff[r - 1]);
      ans += after - before;
    }

    cout << ans << endl;
  }

  accumulate(diff.begin(), diff.end(), 0);

  return 0;
}
