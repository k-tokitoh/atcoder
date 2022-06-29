#include <iostream>
#include <vector>

using namespace std;

class Seq {
public:
  char c;
  long long n;
};

int main() {
  long long N;
  cin >> N;

  vector< Seq > v;

  for (long long i = 0; i < N; i++) {
    char c;
    cin >> c;
    if (i == 0 || v.back().c != c) {
      Seq seq = Seq();
      seq.c = c;
      seq.n = 1;
      v.push_back(seq);
    } else {
      v.back().n += 1;
    }
  }

  long long same = 0;
  for (long long i = 0; i < v.size(); i++) {
    same += (v[i].n * (v[i].n + 1)) / 2;
  }

  long long ans = (N * (N + 1)) / 2 - same;

  cout << ans << endl;

  return 0;
}
