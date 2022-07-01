#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 隣接リストによるダイクストラ法
// edgeの不在はINF_LLにより表現する
vector< long long >
daijkstra(long long const s,
          vector< vector< pair< long long, long long > > > const &m) {
  long long N = m.size();
  vector< long long > ret(N);
  priority_queue< pair< long long, long long >,
                  vector< pair< long long, long long > >,
                  greater< pair< long long, long long > > >
      pq;

  // 初期化する
  for (long long i = 0; i < N; i++) {
    ret[i] = LLONG_MAX;
  }

  ret[s] = 0;
  pq.push(make_pair(0, s));

  while (0 < pq.size()) {
    pair< long long, long long > v = pq.top();
    pq.pop();

    long long cur_v = v.second;
    if (ret[cur_v] < v.first) {
      continue;
    }
    // 着目したnodeに基づきそこから行けるnodeの最小コストを更新する&優先度つきキューにpushする
    for (long long i = 0; i < m[cur_v].size(); i++) {
      pair< long long, long long > edge = m[cur_v][i];
      long long to = edge.first;
      long long cost = ret[cur_v] + edge.second;
      if (cost < ret[to]) {
        ret[to] = cost;
        pq.push(make_pair(cost, to));
      }
    }
  }
  return ret;
}

int main() {
  long long N, M;
  cin >> N >> M;

  vector< vector< pair< long long, long long > > > m(
      N, vector< pair< long long, long long > >(0));

  for (long long i = 0; i < M; i++) {
    long long a, b, c;
    cin >> a >> b >> c;

    m[a - 1].push_back(make_pair(b - 1, c));
    m[b - 1].push_back(make_pair(a - 1, c));
  }

  vector< long long > c = daijkstra(0, m);
  vector< long long > rc = daijkstra(N - 1, m);

  for (long long i = 0; i < N; i++) {
    cout << c[i] + rc[i] << endl;
  }

  return 0;
}
