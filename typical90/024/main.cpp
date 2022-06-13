#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  // ひとつめの配列を保持する
  vector< int > A(N);
  int diff = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  // ふたつめの配列と、各要素の差分を計算して足し合わせていく
  for (int i = 0; i < N; i++) {
    int b;
    cin >> b;
    diff += abs(A[i] - b);
  }

  // 以下をかつでみたすならばYes
  // - 差分の累計が操作可能回数の範囲内
  // - 余分な操作回数が偶数であり元に戻せる
  cout << (diff <= K && (K - diff) % 2 == 0 ? "Yes" : "No") << endl;
  return 0;
}
