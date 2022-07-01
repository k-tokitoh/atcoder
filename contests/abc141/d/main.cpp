#include <iostream>
#include <queue>

using namespace std;

int main() {
  long long N, M;
  cin >> N >> M;

  priority_queue< long long > q;
  for (long long i = 0; i < N; i++) {
    long long a;
    cin >> a;
    q.push(a);
  }

  for (long long i = 0; i < M; i++) {
    long long a = q.top();
    q.pop();
    q.push(a / 2);
  }

  long long ans = 0;
  long long s = q.size();
  for (long long i = 0; i < s; i++) {
    // long long t = q.top();
    // cout << t << endl;
    // ans = t;
    ans += q.top();
    q.pop();
  }

  cout << ans << endl;

  return 0;
}
