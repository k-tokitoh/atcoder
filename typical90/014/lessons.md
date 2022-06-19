- 部分の最適化を全体に適用することで全体としても最適化される、ってのが貪欲法らしい
- 交差を取り除くと不便さの合計は同じか減少するの、直感的にはすぐわかったけど、いくつか場合分けして確かめてみた
- ソートは以下

```cpp
#include <vector>
#include <algorithm>

vector< int > A;
sort(A.begin(), A.end());
```
