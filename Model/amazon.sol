###
###    AMPL Model: Distribution Problem for eCommerce
###


### SOPTのオプションと実行
print "まず、ルート変数の整数化はリラックスし、DC変数のみの最適化を行います。";
option sopt_options 'lplog bktsze=20000 srclev=2 iptime=100';
let {j in Routes} X[j].relax := 1;
solve;

print "次にこの結果からDC拠点は固定化し、ルート変数の最適化を行います。";
option sopt_options 'lplog bktsze=20000 iptime=10';
let {j in Routes} X[j].relax := 0;
fix {i in SC_Sites} Y[i];
solve;

print "最適化が終了し、レポート作成の準備ができました。";







