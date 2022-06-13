### 方針

- [atcoder では 10**8 まではいける]
- `1 <= N <= 3*10**5`, `1 <= Q <= 3*10**5`なので、単純にループすると 10\*\*10 とかになってアウト
- A を sort して二分探索してあげれば`O(n * log n)`で収まりそう

### 実装

```cpp
#include <vector>
#include <algorithm>

// sortは以下
vector<int> V{4,2,3,5,1};
sort(V.begin(), V.end())

// 二分探索は以下。
vector< int >::iterator pos = lower_bound(V.begin(), V.end(), 3);
int index = distance(A.begin(), pos);
```

最小値は以下。

```cpp
#include <algorithm>

min(1,2)
```
