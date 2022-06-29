#include <cmath>
#include <iostream>
#include <string>

using namespace std;

const long long mod = 1000000000 + 7;

// a^n を m で割った余り
long long modpow(long long a, long long n, long long m) {
  long long ret = 1;
  while (n > 0) {
    if (n & 1) {
      ret = ret * a % m;
    }
    a = a * a % m;
    n >>= 1;
  }
  return ret;
}

// mが素数の場合に、mを法としたaの逆元を求める。
// フェルマーの小定理により、a^{m-2} が逆元となることを利用する。
// a^{m-2} の計算には繰り返し2乗法を用いる。
long long modinv(long long a, long long m) { return modpow(a, m - 2, m); }

// aからbまでの和をmodで割った余り
long long modsum(long long a, long long b) {
  return ((((a + b) % mod) * ((b - a + 1) % mod) % mod) * modinv(2, mod)) % mod;
}

int main() {
  unsigned long long L, R;
  cin >> L >> R;

  unsigned long long base = 1;
  unsigned long long ans = 0;

  for (unsigned long long digit = 1; digit <= 19; digit++) {
    unsigned long long from = max(base, L);
    unsigned long long to = min(base * 10 - 1, R);

    if (from <= to) {
      unsigned long long s = modsum(from, to) * digit % mod;
      ans = (ans + s) % mod;
    }

    base *= 10;
  };

  cout << ans << endl;

  return 0;
}
