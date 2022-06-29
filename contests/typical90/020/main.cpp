#include <iostream>
#include <string>

using namespace std;

int main() {
  long long A, B, C;
  cin >> A >> B >> C;

  long long powed = 1;
  for (int i = 0; i < B; i++) {
    powed *= C;
  }
  string ans = A < powed ? "Yes" : "No";

  cout << ans << endl;

  return 0;
}
