#include <iostream>

using namespace std;

int main() {
  long long N, A, B, C;
  cin >> N >> A >> B >> C;

  long long ans = 9999;
  long long remainder;
  for (long long a = 0; a <= 9999; a++) {
    remainder = N - A * a;
    if (remainder < 0) {
      continue;
    }
    for (long long b = 0; b <= 9999; b++) {
      remainder = N - (A * a + B * b);
      if (remainder < 0) {
        continue;
      }
      if (remainder % C == 0) {

        long long c = remainder / C;
        long long count = a + b + c;
        if (count < ans) {
          ans = count;
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}
