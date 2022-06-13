#include <iostream>

using namespace std;

long long get_gcp(long long x, long long y) {
  long long small, large;
  if (x < y) {
    small = x;
    large = y;
  } else {
    small = y;
    large = x;
  }
  while (true) {
    long long remainder = large % small;
    if (remainder == 0) {
      break;
    }
    large = small;
    small = remainder;
  }
  return small;
}

int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long gcp = get_gcp(a, get_gcp(b, c));

  cout << (a / gcp - 1) + (b / gcp - 1) + (c / gcp - 1) << endl;
  return 0;
}
