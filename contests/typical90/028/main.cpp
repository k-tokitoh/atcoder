#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector< vector< int > > d(1001, vector< int >(1001, 0));

  for (int i = 0; i < N; i++) {
    int lx, ly, rx, ry;
    cin >> lx >> ly >> rx >> ry;

    d[lx][ly]++;
    d[rx][ry]++;
    d[lx][ry]--;
    d[rx][ly]--;
  }

  for (int i = 0; i < d.size(); i++) {
    for (int j = 0; j < d[i].size(); j++) {
      int diff = j == 0 ? 0 : d[i][j - 1];
      d[i][j] += diff;
    }
  }

  for (int i = 0; i < d.size(); i++) {
    for (int j = 0; j < d[i].size(); j++) {
      int diff = i == 0 ? 0 : d[i - 1][j];
      d[i][j] += diff;
    }
  }

  vector< int > memo(N + 1, 0);

  for (int i = 0; i < d.size(); i++) {
    for (int j = 0; j < d[i].size(); j++) {
      memo[d[i][j]]++;
    }
  }

  for (int i = 1; i <= N; i++) {
    cout << memo[i] << endl;
  }

  return 0;
}
