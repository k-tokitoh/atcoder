#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int mod = 1000000000 + 7;

int main() {
  int N;
  cin >> N;

  string word = "atcoder";
  vector< int > memo(7, 0);

  for (int i = 0; i < N; i++) {
    char a;
    cin >> a;

    for (int j = 0; j < word.length(); j++) {
      if (a == word[j]) {
        long long add = j == 0 ? 1 : memo[j - 1];
        memo[j] = (memo[j] + add) % mod;
      }
    }
  }
  cout << memo[word.size() - 1] << endl;

  return 0;
}
