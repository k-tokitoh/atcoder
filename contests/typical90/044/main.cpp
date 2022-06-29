#include <deque>
#include <iostream>

using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;

  deque< int > A(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  for (int i = 0; i < Q; i++) {
    int t, x, y;
    cin >> t >> x >> y;

    switch (t) {
    case 1: {
      int tmp = A[x - 1];
      A[x - 1] = A[y - 1];
      A[y - 1] = tmp;
    } break;
    case 2: {
      A.push_front(A.back());
      A.pop_back();
    } break;
    case 3:
      cout << A[x - 1] << endl;
      break;
    }
  }

  return 0;
}
