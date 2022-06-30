- ダイクストラ法の練習
- 一般には未確定のノードのうち最小の値をもつノードから順に確定させていくが、この問題ではグラフが特殊な形をしているため
  - グラフの表現に隣接リスト/隣接行列を用いる必要がなく vector で十分であり
  - 確定させる順序も最初に最小の値をもつ要素を特定したあとは順次 vector の次の要素が定まる
- vector の min/max は以下

```cpp
#include <algorithm>

vector< int >v;

// index は以下で求められる
size_t i = distance(T.begin(), min_element(T.begin(), T.end()));

// 値 は以下で求められる
v[i];
```
