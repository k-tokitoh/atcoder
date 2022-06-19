#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector< int > nodes(N, 0);

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    vector< int > n = {a, b};
    sort(n.begin(), n.end());
    nodes[n[1] - 1] += 1;
  }

  int ans = 0;

  for (int i = 0; i < N; i++) {
    if (nodes[i] == 1) {
      ans += 1;
    }
  }

  cout << ans << endl;

  return 0;
}
