#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector< vector< int > > A(H, vector< int >(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A[i][j];
    }
  }
  vector< vector< int > > B(H, vector< int >(W));

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> B[i][j];
    }
  }

  string ans = "Yes";
  long long count = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (i == H - 1 || j == W - 1) {
        if (A[i][j] != B[i][j]) {
          cout << "No" << endl;
          return 0;
        }
      } else {
        int diff = B[i][j] - A[i][j];
        A[i][j] += diff;
        A[i + 1][j] += diff;
        A[i][j + 1] += diff;
        A[i + 1][j + 1] += diff;
        count += abs(diff);
      }
    }
  }

  cout << "Yes" << endl << count << endl;

  return 0;
}
