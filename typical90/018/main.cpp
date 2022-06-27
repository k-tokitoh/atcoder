#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long T, L, X, Y, Q;
  cin >> T >> L >> X >> Y >> Q;

  for (int i = 0; i < Q; i++) {
    long double e;
    cin >> e;
    long double t = (e / T) * (2.0L * M_PI);
    long double y = cos(-t - M_PI / 2.0L) * L / 2.0L;
    long double z = sin(-t - M_PI / 2.0L) * (L / 2.0L) + (L / 2.0L);
    long double xd = X;
    long double yd = abs(Y - y);
    long double zd = z;

    printf("%.12Lf\n", atan2(zd, sqrt(xd * xd + yd * yd)) * 180.0L / M_PI);
  }

  return 0;
}
