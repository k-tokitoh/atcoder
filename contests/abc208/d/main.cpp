#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// 隣接行列を受け取り、任意のnodeから任意のnodeへの最短経路のコストを求める
long long floyd_warhall(vector< vector< long long > > d) {
  long long ret = 0;
  long long n = d.size();
  for (long long k = 0; k < n; k++) {
    for (long long i = 0; i < n; i++) {
      if (d[i][k] == LLONG_MAX) {
        continue;
      }
      for (long long j = 0; j < n; j++) {
        if (d[k][j] == LLONG_MAX) {
          continue;
        }
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }

    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < n; j++) {
        if (d[i][j] != LLONG_MAX) {
          ret += d[i][j];
        }
      }
    }
  }

  return ret;
}

int main() {
  long long N, M;
  cin >> N >> M;

  vector< vector< long long > > d(N, vector< long long >(N, LLONG_MAX));

  for (long long i = 0; i < N; i++) {
    d[i][i] = 0;
  }

  for (long long i = 0; i < M; i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    d[a - 1][b - 1] = c;
  }

  long long ans = floyd_warhall(d);

  cout << ans << endl;

  return 0;
}
