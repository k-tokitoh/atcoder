#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector< long long > A(46, 0);
  for (int i = 0; i < N; i++) {
    int n;
    cin >> n;
    A[n % 46]++;
  }

  vector< long long > B(46, 0);
  for (int i = 0; i < N; i++) {
    int n;
    cin >> n;
    B[n % 46]++;
  }

  vector< long long > C(46, 0);
  for (int i = 0; i < N; i++) {
    int n;
    cin >> n;
    C[n % 46]++;
  }

  long long ans = 0;

  for (int i = 0; i < 46; i++) {
    for (int j = 0; j < 46; j++) {
      for (int k = 0; k < 46; k++) {
        if ((i + k + j) % 46 == 0) {
          ans += A[i] * B[j] * C[k];
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}
