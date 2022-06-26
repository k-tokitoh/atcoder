# prerequisites

- [online-judge-tools/oj](https://github.com/online-judge-tools/oj)
- [Tatamo/atcoder-cli](https://github.com/Tatamo/atcoder-cli)

# how to use

```
oj login -u "USER_NAME" -p "PASSWORD" "https://atcoder.jp/"
acc new CONTEST_ID
cd CONTEST_ID
acc add
touch main.cpp
g++ -std=gnu++17 main.cpp && oj t -d tests
acc submit main.cpp
```
