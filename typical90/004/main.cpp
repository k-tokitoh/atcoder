#include <iostream>
#include <vector>

using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector< vector< int > > a(H, vector< int >(W));
  vector< int > col(H, 0);
  vector< int > row(W, 0);

  // 入力を二次元配列に入れる
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int n;
      cin >> n;
      a[i][j] = n;
      col[i] += n;
      row[j] += n;
    }
  }

  // 出力する二次元配列をつくりつつ出力する
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << (col[i] + row[j] - a[i][j]);
      if (j + 1 != W) {
        cout << " ";
      }
    }
    cout << endl;
  }

  return 0;
}
