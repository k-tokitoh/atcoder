#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector< long long > S(N);
  vector< long long > T(N);
  vector< long long > ans(N);

  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> T[i];
  }

  size_t start = distance(T.begin(), min_element(T.begin(), T.end()));

  ans[start] = T[start];
  for (long long index = start + 1; index % N != start; index++) {
    ans[index % N] =
        min(T[index % N], ans[(index - 1) % N] + S[(index - 1) % N]);
  }

  for (int i = 0; i < N; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}
