#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Distance {
public:
  Distance(int from, int to, int value) : from(from), to(to), value(value) {}
  int to, value;

private:
  int from;
};

class Tree {
public:
  Tree(int n) : g(n, vector< int >(0)){};

  void set(int n, int m) {
    g[n].push_back(m);
    g[m].push_back(n);
  };

  // あるnodeが与えられたら、それをfromとする最も遠いDistance（のうちのひとつ）を返す
  Distance longest(int from, vector< bool > &seen) {
    Distance ret(INT32_MAX, INT32_MAX, 0);
    seen[from] = true;

    int count = 0;
    for (int i = 0; i < g[from].size(); i++) {
      int next = g[from][i];
      if (!seen[next]) {
        count++;
      }
    }
    if (count == 0) {
      return Distance(from, from, 0);
    } else {
      for (int i = 0; i < g[from].size(); i++) {
        int next = g[from][i];
        if (!seen[next]) {
          Distance d = longest(next, seen);
          int d_value = d.value + 1;
          if (ret.value < d_value) {
            ret = Distance(from, d.to, d.value + 1);
          }
        }
      }
      return ret;
    }
  }

private:
  vector< vector< int > > g;
};

int main() {
  int N;
  cin >> N;

  Tree t = Tree(N);

  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    t.set(a - 1, b - 1);
  }

  vector< bool > seen1 = vector< bool >(N, false);
  int end = t.longest(0, seen1).to;

  vector< bool > seen2 = vector< bool >(N, false);
  int diameter = t.longest(end, seen2).value;

  cout << diameter + 1 << endl;

  return 0;
}
