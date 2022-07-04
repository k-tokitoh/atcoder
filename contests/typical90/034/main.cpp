#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  // 数値iの出現回数をcounter[i]で保持する
  map< int, int > counter;
  vector< int > A(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int from = 0, to = 0;
  // 現在の範囲内の数値の種類数
  int count = 1;
  int ans = 0;
  counter[A[0]] = 1;
  while (from < N && to < N) {
    if (K < count) {
      // もし種類数がKより大きいなら
      // 左端を動かして範囲を狭める
      from++;

      // 範囲から外れた数値の
      int removed = A[from - 1];
      // 出現回数をデクリメントしつつ、その結果出現回数が0になったならば
      if (--counter[removed] == 0) {
        // 種類数もデクリメントする
        count--;
      }
    } else {
      // もし種類数がK以下なら
      // 回答となる最大値を可能ならば更新し
      ans = max(ans, to - from + 1);
      // 右端を動かして引き続き範囲を広げる
      to++;

      // 新たに範囲に入った数値の
      int added = A[to];
      // 出現回数をインクリメントしつつ、その結果出現回数が元々0だったならば
      if (counter[added]++ == 0) {
        // 種類数もインクリメントする
        count++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
