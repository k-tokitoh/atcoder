#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  // クラスごとに累積和を保持する配列を用意する
  vector< vector< int > > sums(2);
  for (int i = 0; i < 2; i++) {
    vector< int > sum(N);
    sums[i] = sum;
  }

  // 入力を受け取りつつ累積和を計算していく
  for (int i = 0; i < N; i++) {
    int cls, score;
    cin >> cls >> score;
    for (int j = 0; j < 2; j++) {
      sums[j][i] = (i == 0 ? 0 : sums[j][i - 1]);
    }
    sums[cls - 1][i] += score;
  }

  // 質問に回答していく
  int Q;
  cin >> Q;

  for (int i = 0; i < Q; i++) {
    int L, R;
    cin >> L >> R;
    for (int j = 0; j < 2; j++) {
      cout << (sums[j][R - 1] - (L == 1 ? 0 : sums[j][L - 2]));
      if (j == 0) {
        cout << " ";
      } else {
        cout << endl;
      }
    }
  }

  return 0;
}
