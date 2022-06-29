#include <cmath>
#include <iostream>
#include <numeric>
#include <string>

using namespace std;

int main() {
  long long A, B;
  cin >> A >> B;

  long long r = gcd(A, B);
  long long a = A / r;

  // lcm = a * b * r = a * B <= 10**18
  // すなわち a <= 10**18 / B
  long long p = pow(10, 18);
  string ret = a <= p / B ? to_string(a * B) : "Large";

  cout << ret << endl;

  return 0;
}
