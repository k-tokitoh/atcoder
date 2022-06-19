### 変換

#### int to char

```cpp
char c = n + '0';
```

#### char to int

```cpp
int n = c - '0';
```

#### string to int

```cpp
#include <string>

int n = stoi(str);
```

#### int to string

```cpp
#include <string>

string str = to_string(n);
```

### べき乗

```cpp
#include <cmath>

pow(10, 3);
```

### 文字列の置換

```cpp
#include <regex>

regex_replace(str, regex("foo"), "bar");
```

### long long の整数リテラル

```cpp
1LL;
```

### クォーテーション

```cpp
char c = 'x'
string s = "x"
```

### pow

- double を返すので、long long と扱える値の範囲が異なるみたい？
- n 進法展開の場合は pow ではなく基数のべき乗や商を都度再代入していくのがよさそう。
