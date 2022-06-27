#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector< vector< int > > t(N, vector< int >(N));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> t[i][j];
    }
  }

  int M;
  cin >> M;

  vector< set< int > > rumor(M);

  for (int i = 0; i < M; i++) {
    int m1, m2;
    cin >> m1 >> m2;
    rumor[i] = set< int >{m1 - 1, m2 - 1};
  }

  vector< int > order(N);

  for (int i = 0; i < N; i++) {
    order[i] = i;
  }

  int min = 1000 * 10 + 1;

  do {
    int sum = 0;
    bool is_taboo = false;
    for (int section = 0; section < N; section++) {
      int member = order[section];

      if (0 < section) {
        int prev_member = order[section - 1];
        set< int > combi = {prev_member, member};
        for (int j = 0; j < M; j++) {
          if (rumor[j] == combi) {
            is_taboo = true;
            break;
          }
        }
      }

      if (is_taboo) {
        break;
      }
      sum += t[member][section];
    }
    if (!is_taboo && sum < min) {
      min = sum;
    }
  } while (next_permutation(order.begin(), order.end()));

  int ans = min == 1000 * 10 + 1 ? -1 : min;

  cout << ans << endl;

  return 0;
}
