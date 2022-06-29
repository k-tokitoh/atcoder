#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  long long sum = 0;
  vector< int > A(N * 2);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A[i] = a;
    A[i + N] = a;
    sum += a;
  }

  string ans;

  if (sum % 10 != 0) {
    ans = "No";
  } else {
    int from = 0;
    int to = 1;
    long long val = A[0];
    ans = "No";
    while (to <= from + N) {
      if (val == sum / 10) {
        ans = "Yes";
        break;
      } else if (val < sum / 10 || from + 1 == to) {
        val += A[to];
        to++;
      } else if (sum / 10 < val) {
        val -= A[from];
        from++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
