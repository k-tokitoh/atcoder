- 繰り返し 2 乗法
  - $a^b$ を mod で割った余りは、$b$ が $10^{18}$ のように巨大であっても短時間で求めることができる
  - シンプルに乗じていくと $O(b)$の計算が必要
  - しかしたとえば$5^{13}$は$5^{8}*5^{4}*5^{1}$のように表せることを利用すると、
  - 右辺の各項の mod で割った余りを求めて乗じていくのはたかだか $\log N$の計算で実行できる
