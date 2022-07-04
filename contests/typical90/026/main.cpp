#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Tree {
public:
  Tree(int n) : g(n, vector< int >(0)), groups(n, INT32_MAX) {}

  // まだ分類されていなければINT32_MAX, 分類されていれば0 or 1
  vector< int > groups;

  void connect(int n, int m) {
    g[n].push_back(m);
    g[m].push_back(n);
  }

  void group(int node, int igroup) {
    groups[node] = igroup;

    for (int i = 0; i < g[node].size(); i++) {
      int next = g[node][i];
      if (groups[next] == INT32_MAX) {
        int next_group = !igroup;
        group(next, !igroup);
      }
    }
  }

  int larger_group() {
    vector< int > vgroups_count = groups_count();
    return vgroups_count[0] < vgroups_count[1] ? 1 : 0;
  }

  int root() {
    for (int i = 0; i < g.size(); i++) {
      if (g[i].size() == 1) {
        return i;
      }
    }
    throw("root() is expected to return some node.");
  }

private:
  vector< int > groups_count() {
    vector< int > ret(2, 0);
    for (int i = 0; i < groups.size(); i++) {
      ret[groups[i]]++;
    }
    return ret;
  }

  vector< vector< int > > g;
};

int main() {
  int N;
  cin >> N;

  Tree t = Tree(N);

  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    t.connect(a - 1, b - 1);
  }

  t.group(t.root(), 1);

  int larger_group = t.larger_group();

  int count = N / 2;
  for (int i = 0; i < N; i++) {
    if (t.groups[i] == larger_group) {
      cout << i + 1;
      count--;
      if (count == 0) {
        break;
      } else {
        cout << " ";
      }
    }
  }

  cout << endl;

  return 0;
}
