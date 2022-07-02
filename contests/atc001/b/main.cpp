#include <iostream>
#include <vector>

using namespace std;

// ランクなし、経路圧縮なし
class UnionFind {
  vector< long long > parents;

public:
  UnionFind(long long n) : parents(n) {
    for (long long i = 0; i < n; i++) {
      parents[i] = i;
    }
  }

  long long root(long long n) {
    long long parent = parents[n];
    return parent == n ? n : root(parent);
  }

  void unite(long long x, long long y) { parents[root(x)] = root(y); }

  bool same(long long x, long long y) { return root(x) == root(y); }
};

int main() {
  long long N, Q;
  cin >> N >> Q;

  UnionFind uf = UnionFind(N);

  for (long long i = 0; i < Q; i++) {
    long long p, a, b;
    cin >> p >> a >> b;

    if (p == 0) {
      uf.unite(a, b);
    } else {
      cout << (uf.same(a, b) ? "Yes" : "No") << endl;
    }
  }

  return 0;
}
