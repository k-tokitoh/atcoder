- 「n 桁の数をまとめて、等差数列の和で計算する」というところは自力で発想できた

### 逆元

- [mod の除算だけはそのままできず、逆元をかける必要がある](https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a#3-%E5%89%B2%E3%82%8A%E7%AE%97-a--b)
- 逆元の求め方には以下がある

  - ユークリッドの互除法
    - 以下を理解した
      - [最小公倍数を求めるのを拡張した手順で一次不定方程式が解けること](https://www.youtube.com/watch?v=2t8UepAuWcM)
      - [$a$と$mod$が互いに素 <=> $ax+mod*y=1$が解をもつ](https://manabitimes.jp/math/674) => $mod$ を法とする $a$ の逆元が存在する
  - フェルマーの小定理
    - 以下を理解した
      - [$a^{p-1}\equiv a \mod p$の 2 つの証明](https://manabitimes.jp/math/680)
    - 最小 2 乗法により$a^{p-2}$の剰余、すなわち p を法とする a の逆元を求めるアルゴリズムを実装した

### unsigned long long

$10^19$は long long では扱えないことに注意する。

```
>>> 10**19 < 2**63
False
>>> 10**19 < 2**64
True
```
