#include <iostream>
#include <vector>

using namespace std;

long long N, L, K;
vector< long long > A(N + 1);

// 長さl以上のK+1個に分割できるか判定する
bool can_divide(int l) {
  int tmp = 0;
  int count = 0;
  for (int i = 0; i < A.size(); i++) {
    tmp += A[i];
    if (l <= tmp) {
      tmp = 0;
      count++;
    }
  }
  return K + 1 <= count;
}

int main() {
  cin >> N >> L >> K;
  cin >> A[0];
  int sum = A[0];
  for (int i = 1; i < N; i++) {
    int a;
    cin >> a;
    A.push_back(a - sum);
    sum += a - sum;
  }
  A.push_back(L - sum);

  int left = 1;
  int right = L / (K + 1) + 1;

  while (1 < right - left) {
    int mid = (left + right) / 2;
    can_divide(mid) ? left = mid : right = mid;
  }

  cout << left << endl;

  return 0;
}
