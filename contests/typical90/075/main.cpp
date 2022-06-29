#include <cmath>
#include <iostream>

using namespace std;

long long factorsCount(long long n) {
  long long ret = 0;
  long long r = n;
  for (long long d = 2; d <= sqrt(n); d++) {
    while (r % d == 0) {
      ret++;
      r /= d;
    }
  }
  if (r != 1) {
    ret++;
  }
  return ret;
}

int main() {
  long long N;
  cin >> N;

  long long fc = factorsCount(N);
  long long ans = 0;
  long long capacity = 1;
  while (capacity < fc) {
    ans++;
    capacity *= 2;
  }

  cout << ans << endl;

  return 0;
}
