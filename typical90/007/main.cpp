#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long N;
  cin >> N;
  vector< long long > A(N);
  for (long long i = 0; i < N; i++) {
    cin >> A[i];
  }
  // 配列をsortする
  sort(A.begin(), A.end());

  long long Q;
  cin >> Q;

  for (long long i = 0; i < Q; i++) {
    long long b;
    cin >> b;

    // 二分探索する
    vector< long long >::iterator pos = lower_bound(A.begin(), A.end(), b);
    long long index = distance(A.begin(), pos);

    long long diff;
    if (index == 0) {
      diff = abs(b - A[index]);
    } else {
      diff = min(abs(b - A[index]), abs(b - A[index - 1]));
    }
    cout << diff << endl;
  }

  return 0;
}
