#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, L;
  cin >> N >> L;

  vector< long long > v(N, 0);
  v[0] = 1;

  for (int i = 1; i < N; i++) {
    v[i] = v[i - 1];
    if (i == L - 1) {
      v[i] += 1;
    } else if (0 <= i - L) {
      v[i] += v[i - L];
    }
    v[i] %= 1000000000 + 7;
  }

  cout << v.back() << endl;

  return 0;
}
