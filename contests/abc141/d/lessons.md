- はじめての優先度つきキュー
- この問題の計算量
  - 配列で都度 sort して取り出そうとすると、マージソートとかでも O(N\*log N)なので全体としては O(M\*N\*log N)で TLE になる
  - 優先度つきキューなら最初に push していくのが N\*log N, 順次取り出していくのが M\*log N なので収まる
- 構造は[こちらで](https://qiita.com/birdwatcher/items/9e6dac869dea023bf53c#priority_queue-%E5%84%AA%E5%85%88%E5%BA%A6%E4%BB%98%E3%81%8D%E3%82%AD%E3%83%A5%E3%83%BC)
  - pop/push が O(log N), top が O(1)であることも理解した
- 使い方は以下

```cpp
#include <queue>

priority_queue< long long > q;
q.push(1);
q.push(3);
q.push(2);
q.top();  // 3が返る
q.pop();  // voidが返る、中身が1,2になる
```
