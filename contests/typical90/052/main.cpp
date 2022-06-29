#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  long long ans = 1;

  for (int i = 0; i < N; i++) {
    int a1, a2, a3, a4, a5, a6;
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;

    ans *= (a1 + a2 + a3 + a4 + a5 + a6);
    ans %= 1000000000 + 7;
  }

  cout << ans << endl;

  return 0;
}
