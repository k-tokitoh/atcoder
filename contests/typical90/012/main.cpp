#include <iostream>
#include <vector>

using namespace std;

using P = pair< int, int >;

class UnionFind {
public:
  UnionFind(int h, int w) : parents(h, vector< P >(w)) {
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        parents[i][j] = make_pair(i, j);
      }
    }
  }

  void unite(P p1, P p2) {
    P p1r = root(p1);
    P p2r = root(p2);
    set_parent(p1r, p2r);
  }

  bool same(P p1, P p2) { return root(p1) == root(p2); }

private:
  vector< vector< P > > parents;

  P get_parent(P p) { return parents[p.first][p.second]; }

  void set_parent(P p, P c) { parents[c.first][c.second] = p; }

  P root(P p) {
    P pp = get_parent(p);
    if (pp == p) {
      return p;
    } else {
      P pr = root(pp);
      set_parent(pr, p);
      return pr;
    }
  }
};

int main() {
  int H, W, Q;
  cin >> H >> W >> Q;

  vector< vector< bool > > b = vector(H, vector< bool >(W, false));

  UnionFind uf = UnionFind(H, W);

  for (int i = 0; i < Q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int r, c;
      cin >> r >> c;
      b[r - 1][c - 1] = true;

      if (r < H && b[r][c - 1]) {
        uf.unite(make_pair(r - 1, c - 1), make_pair(r, c - 1));
      }
      if (0 <= r - 2 && b[r - 2][c - 1]) {
        uf.unite(make_pair(r - 1, c - 1), make_pair(r - 2, c - 1));
      }
      if (c < W && b[r - 1][c]) {
        uf.unite(make_pair(r - 1, c - 1), make_pair(r - 1, c));
      }
      if (0 <= c - 2 && b[r - 1][c - 2]) {
        uf.unite(make_pair(r - 1, c - 1), make_pair(r - 1, c - 2));
      }
    } else if (t == 2) {
      int ra, ca, rb, cb;
      cin >> ra >> ca >> rb >> cb;

      cout << (b[ra - 1][ca - 1] && uf.same(make_pair(ra - 1, ca - 1),
                                            make_pair(rb - 1, cb - 1))
                   ? "Yes"
                   : "No")
           << endl;
      ;
    }
  }

  return 0;
}
