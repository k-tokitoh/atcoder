#include <iostream>
#include <string>

using namespace std;

bool satisfied(string str) {
  int depth = 0;
  for (int i = 0; i < str.size(); i++) {
    char c = str[i];
    c == '(' ? depth++ : depth--;
    if (depth < 0) {
      return false;
    }
  }
  return depth == 0;
}

int main() {
  long long N;
  cin >> N;

  if (N % 2 == 1) {
    cout << endl;
  }

  for (int bit = 0; bit < (1 << N); bit++) {
    string str = "";
    for (int i = 0; i < N; i++) {
      str = ((bit & (1 << i)) ? ')' : '(') + str;
    }
    if (satisfied(str)) {
      cout << str << endl;
    }
  }

  return 0;
}
