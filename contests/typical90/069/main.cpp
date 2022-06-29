#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000000000 + 7;

// a ** b を mod でわった余りを求める
long long power(long long a, long long b) {
  long long ret = 1;
  do {
    if (b % 2 == 1) {
      ret = ret * a % mod;
    }
    a = a * a % mod;
    b = b / 2;
  } while (0 < b);
  return ret;
}

int main() {
  long long N, K;
  cin >> N >> K;

  long long ans = 1;

  if (K == 1) {
    ans = N == 1 ? 1 : 0;
  } else if (K == 2) {
    ans = N < 3 ? 2 : 0;
  } else if (2 < K) {
    switch (N) {
    case 1:
      ans = K;
      break;
    case 2:
      ans = K * (K - 1) % mod;
      break;
    default:
      ans = K * (K - 1) % mod * power(K - 2, N - 2) % mod;
    }
  }

  cout << ans << endl;

  return 0;
}
