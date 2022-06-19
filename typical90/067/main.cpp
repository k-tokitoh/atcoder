#include <cmath>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

long long to_ll(string str, int base) {
  long long n = 0, x = 1;
  for (int i = str.length() - 1; 0 <= i; i--) {
    n += (str[i] - '0') * x;
    x *= base;
  }
  return n;
}
string to_str(long long n, int base) {
  string ret = "";
  if (n == 0) {
    return "0";
  }
  while (0 < n) {
    char c = ((n % base) + '0');
    ret = c + ret;
    n /= base;
  }
  return ret;
}

int main() {
  string N;
  int K;
  cin >> N >> K;

  for (int i = 0; i < K; i++) {
    N = regex_replace(to_str(to_ll(N, 8), 9), regex("8"), "5");
  }

  cout << N << endl;

  return 0;
}
