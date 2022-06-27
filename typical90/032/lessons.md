- やったぜ自力 AC
  - 全探索でいけそう、とみおとしをたてることができた
    - `10*9*8*7*6*5*4*3*2*1 * 10 < 10**9 # True`
- 集合は以下で扱える

```cpp
#include <set>

set< int >s = {1,2,3};
```

- 順列は以下で

```cpp
#include <algorithm>
#include <vector>

vector< int >v = {1,2,3};

do {
  // whatever
} while (next_permutation(v.begin(), v.end()));
```
