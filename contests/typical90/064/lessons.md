- 階差というキーワードだけみて自力 AC
- 都度絶対値を書き換えていくと 10\*\*5 \* 10\*\*5 で LTE になりそう、とはまず思った
- バコンと上がるなら、l-r で挟まれた部分は不便さに変化がなく、境界だけ考えればいいので地殻変動 1 回あたりの処理が定数時間に収まることに気づけた
- vector の合計などの折りたたみ演算は以下でできる

```cpp
#include <numeric>
#include <vector>

vector< int >v = {1,2,3};
accumulate(v.begin(), v.end(), 0);
```