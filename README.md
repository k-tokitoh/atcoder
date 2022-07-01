# prerequisites

- [online-judge-tools/oj](https://github.com/online-judge-tools/oj)
- [Tatamo/atcoder-cli](https://github.com/Tatamo/atcoder-cli)
- [sagiegurari/cargo-make](https://github.com/sagiegurari/cargo-make)

# how to use

```sh
cargo make init
oj login -u "USER_NAME" -p "PASSWORD" "https://atcoder.jp/"
cargo make new CONTEST_ID
cargo make add CONTEST_ID
cargo make test CONTEST_ID/TASK_ID
cargo make submit CONTEST_ID/TASK_ID

## count solved provlems
cd CONTEST_ID
echo $((`ls -l | wc -l` -1))  # exclude contest.acc.json
```
