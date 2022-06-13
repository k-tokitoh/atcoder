# prerequisites

- [online-judge-tools/oj](https://github.com/online-judge-tools/oj)
- [Tatamo/atcoder-cli](https://github.com/Tatamo/atcoder-cli)

# how to use

```
oj login -u "USER_NAME" -p "PASSWORD" "https://atcoder.jp/"
acc new CONTEST_ID
acc add
cd CONTEST_ID
touch main.cpp
g++ main.cpp && oj t -d tests
acc submit main.cpp
```
