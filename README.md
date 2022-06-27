# prerequisites

- [online-judge-tools/oj](https://github.com/online-judge-tools/oj)
- [Tatamo/atcoder-cli](https://github.com/Tatamo/atcoder-cli)

# how to use

## solve problems

```sh
oj login -u "USER_NAME" -p "PASSWORD" "https://atcoder.jp/"
acc new CONTEST_ID
cd CONTEST_ID
acc add
touch main.cpp
g++ -std=gnu++17 main.cpp && oj t -d tests
acc submit main.cpp
```

## count solved provlems

```sh
cd CONTEST_ID
echo $((`ls -l | wc -l` -1))  # exclude contest.acc.json
```
