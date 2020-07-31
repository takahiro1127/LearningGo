# Portfolio selection using neural network
## energy function
N個の変数がN個のニューロンに対応している。
ここでニューロンに入るのはどの株にどれだけの割合で投資するかという変数　つまりxiである

energy functionは以下のようになる
Ex = ...
これは最小化したい以下の式
fx = ...
について
wij = ...
bi = ...
とする事で対応関係になることがわかる。

## network dynamics
ニューロンiのタイミングtでの値をxtとおく
x(t + 1) = G(h(t))
h(t) = sigma wx + b
g = sigmoid

beta > 0, gammaはhi(0)の平均値

## constrains
最初はxiは下限にセットしてある

pareto optimal solutionを本物のかいtおる
