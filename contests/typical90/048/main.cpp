#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  vector< int > v(2 * N);

  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back(a - b);
    v.push_back(b);
  }

  sort(v.begin(), v.end());

  long long ans = 0;

  for (int i = v.size() - K; i < v.size(); i++) {
    ans += v[i];
  }

  cout << ans << endl;

  return 0;
}
